//---------------------------------------------------------------------------

#pragma hdrstop

#include "ParallelDemos.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
// demoLowAndHighPriorityLocksWithMutex
//  * implementation LowPriorityLock and HighPriorityLock with std::mutex
//  * std::thread constructor
//  * std::thread.join()
//---------------------------------------------------------------------------

#include <iostream>
#include <mutex>
#include <chrono>
#include <thread>

std::mutex M;
std::mutex N;
std::mutex L;

void LowPriorityLock(){
	L.lock();
	N.lock();
	M.lock();
	N.unlock();
}

void LowPriorityUnlock(){
	M.unlock();
	L.unlock();
}

void HighPriorityLock(){
	N.lock();
	M.lock();
	N.unlock();
}

void HighPriorityUnlock(){
	M.unlock();
}

void HighPriorityTask(const char* s){
	HighPriorityLock();
	std::this_thread::sleep_for(std::chrono::milliseconds(2));
	std::cout << s << std::endl;
	HighPriorityUnlock();
}

void LowPriorityTask(const char* s){
	LowPriorityLock();
	std::this_thread::sleep_for(std::chrono::milliseconds(2));
	std::cout << s << std::endl;
	LowPriorityUnlock();
}

void demoLowAndHighPriorityLocksWithMutex(){
	std::thread t0(LowPriorityTask,"  Low priority task: t0 working here");
	std::thread t1(LowPriorityTask,"  Low priority task: t1 working here");
	std::thread t2(LowPriorityTask,"  Low priority task: t2 working here");
	std::thread t3(LowPriorityTask,"  Low priority task: t3 working here");
	std::thread t4(HighPriorityTask,"  !!! High priority task: t4 working here");
	std::thread t5(LowPriorityTask,"  Low priority task: t5 working here");
	//std::cout << "All threads created" << std::endl;
	t0.join();
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
}


//---------------------------------------------------------------------------
// demoParallerHttpGet
//  * std::lock_guard<std::mutex>
//  * std::vector<std::thread>
//---------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <chrono>
#include <thread>
#include <mutex>
#include <random>

std::random_device randomDevice; // obtain a random number from hardware
std::mt19937 generator(randomDevice()); // seed the generator
std::uniform_int_distribution<> distribution(200, 700);

std::mutex mutexDelayGenerator;

int generateResponseDelay () {
	std::lock_guard<std::mutex> guard(mutexDelayGenerator);
	return distribution(generator);
}


std::map<std::string, std::string> webPages;
std::mutex MutexWebPages;

void GetHttpPage(const std::string& url, const std::string& title)
{
	int delay = generateResponseDelay();
	std::this_thread::sleep_for(std::chrono::milliseconds(delay));
	std::string result = "<html><head<title>"+title+"</title></head><body>"+
		"fake content... delay:" + std::to_string(delay) + " ms</body></html>";
	std::lock_guard<std::mutex> guard(MutexWebPages);
	webPages[url] = result;
}

struct UrlRequest {
	std::string title;
	std::string url;
};

void demoParallerHttpGet() {
	std::vector<UrlRequest> requests {
		{"foo","http://www.foo.com"},
		{"bar","http://www.bar.pl"},
		{"abc","http://www.abc.org"},
		{"xyz","http://www.xyz.eu"}
	};
	std::vector<std::thread> downloadThreads;
	for (auto& req : requests) {
		downloadThreads.push_back ( std::thread (GetHttpPage,  req.url,
			req.title) );
	}
	for (auto &t : downloadThreads) {
		t.join();
	}

	// not it's safe to access webPages without lock
	// as the threads are joined
	for (const auto &page : webPages) {
		std::cout << "  "<< page.first << " => " << page.second << std::endl;
	}
}

//---------------------------------------------------------------------------
// demoAtomics
//  *
//---------------------------------------------------------------------------

#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

std::atomic<bool> ready (false);
std::atomic_flag winner = ATOMIC_FLAG_INIT;

void taskCountTo1Milion (int threadId) {
	// wait for the ready signal
	while (!ready)
		std::this_thread::yield();
	// count to 1 million
	for (volatile int i=0; i<1000000; ++i) {
	}
	// first one will set the flag
	if (!winner.test_and_set())
		std::cout << "  The winner is: thread #" << threadId << std::endl;
};

void demoAtomics () {
	std::vector<std::thread> threads;
	std::cout << "  Create 10 threads (count to million) ..." << std::endl;
	for (int i=1; i<=10; ++i) {
		threads.push_back( std::thread (taskCountTo1Milion,i) );
	}
	ready = true;
	// for (auto& th : threads)
	for (std::thread& th : threads)
		th.join();
}

