#include "sylar/sylar.h"

sylar::Logger::ptr g_logger = SYLAR_LOG_ROOT();

void test_fiber() {
    //static int s_count = 5;
    SYLAR_LOG_INFO(g_logger) << "test in fiber s_count";
    //SYLAR_LOG_INFO(g_logger) << "test in fiber s_count" << std::to_string(s_count);

    //sleep(1);
    //if(--s_count >= 0) {
        //sylar::Scheduler::GetThis()->schedule(&test_fiber);
    //}
}

int main() {
    SYLAR_LOG_INFO(g_logger) << "main";
    sylar::Scheduler sc(2, true, "test");
    //std::cout << sylar::Fiber::TotalFibers() << std::endl;
    sc.start();
    //std::cout << sylar::Fiber::TotalFibers() << std::endl;
    //sleep(2);
    sc.schedule(&test_fiber);
    sc.stop();
    SYLAR_LOG_INFO(g_logger) << "over";
    return 0;
}