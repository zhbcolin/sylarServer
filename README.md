# 学习和实现基于协程的高并发服务器框架
## 学习参考
1、https://github.com/sylar-yin/sylar.git  
2、https://github.com/zhongluqiang/sylar-from-scratch.git  
3、https://www.midlane.top/wiki/pages/viewpage.action?pageId=10060952  
4、https://blog.csdn.net/weixin_46267443/category_11487591.html  
## 模块内容
1、日志模块
仿照log4j的格式，以流的形式写日志和格式化日志，方便从日志中定位程序运行过程中出现的问题
2、配置模块
采用约定优于配置的思想，使用yaml-cpp作为YAML解析库，可以从配置文件中读取yaml文件，加载用户配置
3、线程模块
基于pthread实现，包括线程类（thread）和线程同步类（信号量、互斥锁、读写锁等）
4、协程模块
轻量级的、用户态的线程，采用非对称协程模型，将复杂的异步调用封装成同步操作
5、协程调度模块
创建协程调度器，其内部为线程池，实现了N-M的协程调度器，N个线程运行M个协程，协程可以在线程之间进行切换，也可以绑定到指定线程运行
6、IO协程调度模块
继承自协程调度器，封装epoll，支持为socket fd注册读写事件回调函数，并支持定时器超时回调
7、Hook模块
封装与socket相关的底层API，通过hook模块，可以使不具备异步功能的API体现出异步的性能
8、Socket模块
封装了地址类和Socket类，可解析ip地址，便于直接只用socket API
9、ByteArray序列化模块
支持二进制文件到文件的序列化和文件反序列化
10、TcpServer模块
基于Socket类，封装简单的TcpServer服务器类，可作为后续不同业务逻辑的服务器实现的基类
11、Stream模块
封装流式的统一接口，便于使用和扩展
12、HTTP模块
使用Ragel实现HTTP/1.1，利用HttpServer可进行HTTP的连接和会话
13、Servlet模块
仿java的servlet，封装Http请求和响应，便于业务逻辑的实现
14、守护线程模块
保证服务的稳定运行，管理服务进程的启动、重启等
