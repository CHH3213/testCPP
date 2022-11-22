## CppAD+Ipopt demo


### 环境依赖

本demo在Ubuntu20.04下运行。依赖如下
- cmake
- CppAD
- Ipopt

cmake的安装直接终端运行
```shell
sudo apt install cmake
```
CppAD和Ipopt的安装参考[博客资料](https://blog.csdn.net/weixin_42301220/article/details/127946528).


### 编译项目

```bash
mkdir build
cd build
cmake ../
make
```
### 运行项目
在`build`文件夹内，运行

- 测试CppAD
    
    ```bash
    ./CppAD_demo 
     ```
- 测试CppAD+Ipopt
    ```bash
    ./cppad_ipopt_demo  
     ```