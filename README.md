# Http Server Framework

### 只需自定义业务函数 
    void handle(shared_ptr<Http> request, shared_ptr<Http> response) {
        ...
    }
实现业务逻辑，并注册到HttpServer中

### 支持静态路由和正则路由