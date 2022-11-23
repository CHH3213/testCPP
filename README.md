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
  

## OSQP/OSQP-eigen demo

[OSQP](https://osqp.org/docs/get_started/)
是一种二次规划求解器，可用求解线性组合或二次规划问题，在同类问题中求解效率极高！

OSQP是用纯C实现的，但是纯C中对于矩阵和向量的操作不是特别友好，因此为了更方便使用OSQP，在构造C++接口时，引入了Eigen库，方便矩阵和向量的操作。

- 相关类

  osqp-eigen主要是构造了三个类，Data类、Setting类、Solver类：
   
  - Data类：对C语言OSQP中的OSQPData(struct)进行包装
  - Setting类：对C语言OSQP中的OSQPSetting(struct)进行包装 
  - Solver类：对C语言OSQP中的OSQPWorkspace(struct)进行包装

- 求解过程

    1. 创建求解器Solver的实例
    2. 设置Setting参数
    3. 设置Data参数
    4. 初始化求解器Solver
    5. 求解优化问题
    6. 提取最优解

### OSQP与OSQP-eigen安装

- OSQP安装

  ```shell
  git clone --recursive https://github.com/osqp/osqp
  cd osqp
  mkdir build
  cd build
  cmake .. -DBUILD_SHARED_LIBS=ON
  make
  sudo make install
  ```
  
- osqp-eigen安装

  osqp-eigen依赖eigen3，ubuntu系统里内置安装了eigen3包。

  ```shell
  git clone https://github.com/robotology/osqp-eigen.git
  cd osqp-eigen
  mkdir build 
  cd build
  cmake ..    #默认安装在/usr/local/include中,非apt安装的包，不在/usr/include/下，而是/usr/local/include下
  make
  sudo make install
  ```
  
### 测试
首先编译项目
```bash
mkdir build
cd build
cmake ../
make
```

- osqp测试

  ```shell
  ./osqp_demo
  ```

- osqp-eigen测试
  例子来自于[博客](https://www.chuxin911.com/osqp-introduction_20210715/)
  ```shell
  ./osqp_eigen_demo
  ```


