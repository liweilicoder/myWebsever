## webserver
 C++11 编写的webserver服务器
### 功能
* 利用IO复用技术Epoll与线程池实现多线程的Reactor高并发模型；
* 利用正则与状态机解析HTTP请求报文，实现处理静态资源的请求；
* 支持GET/POST请求方式
* 利用C++标准库容器封装char，实现自动增长的缓冲区；
* 基于vector实现小根堆定时器，关闭超时的非活动连接；
* 利用单例模式与阻塞队列实现异步的日志系统，记录服务器运行状态；
* 利用RAII机制实现了mysql数据库连接池，减少数据库连接建立与关闭的开销，同时实现了用户注册登录功能。
* 增加log,threadpool测试单元

### 框图说明
 ![](./resource/webserver.drawio.png)

## sourcecodeYoushuang
《linux高性能服务器编程》 游双 sourcecode


