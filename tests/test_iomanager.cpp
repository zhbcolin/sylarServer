#include "sylar/sylar.h"
#include "sylar/iomanager.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>

sylar::Logger::ptr g_logger = SYLAR_LOG_ROOT();

int sock = 0;

void test_fiber() {
    //sylar::IOManager iom;
    //iom.schedule(&test_fiber);

    SYLAR_LOG_INFO(g_logger) << "test_fiber sock=" << sock;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    fcntl(sock, F_SETFL, O_NONBLOCK);

    sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);
    inet_pton(AF_INET, "182.61.200.1", &addr.sin_addr.s_addr);

    if(!connect(sock, (const sockaddr*)&addr, sizeof(addr))) {

    } else if(errno == EINPROGRESS) {
        SYLAR_LOG_INFO(g_logger) << "add event errno=" << errno << " " << strerror(errno);
        sylar::IOManager::GetThis()->addEvent(sock, sylar::IOManager::READ, [](){
            SYLAR_LOG_INFO(g_logger) << "read callback";
        });
        sylar::IOManager::GetThis()->addEvent(sock, sylar::IOManager::WRITE, [](){
            SYLAR_LOG_INFO(g_logger) << "write callback";
            sylar::IOManager::GetThis()->cancelEvent(sock, sylar::IOManager::READ);
            close(sock);
        });
    } else {
        SYLAR_LOG_INFO(g_logger) << "else " << errno << " " << strerror(errno);
    }
}

sylar::Timer::ptr s_timer;
void test_timer() {
    sylar::IOManager iom(2);
    s_timer = iom.addTimer(1000, [](){
        static int i = 0;
        SYLAR_LOG_INFO(g_logger) << "hello timer i=" << i;
        if(++i == 3) {
            s_timer->cancel();
        }
    }, true);
}

void test1() {
    //SYLAR_LOG_INFO(g_logger) << "test_fiber";
    sylar::IOManager iom(2, true);
    iom.schedule(&test_fiber);
}

int main(int argc, char** argv) {
    //test1();
    test_timer();
     //test_fiber();
    return 0;
}
