# 拉格朗日插值简要介绍 $\text{by Singulet}$

拉格朗日插值 $\text{Lagrange Interpolation}$ ，简称 $LI$ 。\
已知 $n$ 次多项式 $A$ 的 $n+1$ 个点的取值 $(x_i,y_i)(0\le i\le n)$ ，求 $A$ 的表达式。\
解：设函数 $f(x,y)$ 满足：

$$
f(x,y)=\begin{cases}
1,x=y\\
0,x\not ={y}
\end{cases}(x,y\in D)
$$

其中 $D=\set{x_0,x_1,...,x_n}$ 。那么有：

$$
A(x_k)=\sum\limits_{i=0}^{n}{y_if(x_k,x_i)}=y_k(0\le k\le n)
$$

显然，函数 $f(x,y)$ 在这里起到筛选点值的作用，现在我们尝试把 $f(x,y)$ 写成关于 $x$ 的多项式，并取消 $x,y$ 的取值范围限制。\
注意到 $x-y$ 与 $f(x,y)$ 有一些相似之处，只是 $x-y$ 仅在两者相等时取 $0$ ，与 $f(x,y)$ 刚好相反，如果我们把 $D$ 中除 $y$ 以外的所有值 $x_i$ 都枚举一遍，那么 $x-x_i$ 仅在 $x=y$ 时不存在 $0$ 值，把这些值乘起来，得到的值仅在 $x=y$ 时不取 $0$ 值，这样就能和 $f(x,y)$ 对应起来了。\
于是，我们考虑 $g(x,x_k)=\prod\limits_{i\not ={k}}{(x-x_i)}$ ，显然，当 $x\not ={x_k}$ 且 $x\in D$ 时有 $g(x,x_k)=0$ ，当 $x=x_k$ 时有 $g(x,x_k)\not ={0}$ ，这恰好对应了 $f(x,x_k)$ 仅在 $x=x_k$ 时不为 $0$ 。但是， $f(x,x)=1$ ，而 $g(x,x)$ 不一定为 $1$ 。因此，我们还要想办法保证 $g(x,x)=1$ 。\
注意到此时的 $g(x_k,x_k)=\prod\limits_{i\not ={k}}{(x_k-x_i)}$ ，我们设 $B(k)=g(x_k,x_k)$ ，再令 $h(x,x_k)=\frac{g(x,x_k)}{B(k)}$ ，此时 $h(x_k,x_k)$ 就必定取 $1$ ， $h(x_i,x_j)(i\not ={j})$ 就必定取 $0$ ，这样就能和 $f(x,y)$ 完全对应了。\
于是有：

$$
A(x_k)=\sum\limits_{i=0}^{n}{y_ih(x_k,x_i)}=y_k(0\le k\le n)
$$

$$
A(x)=\sum\limits_{i=0}^{n}{y_ih(x,x_i)}=\sum\limits_{i=0}^{n}{y_i\frac{\prod\limits_{j\not ={i}}{(x-x_j)}}{\prod\limits_{j\not ={i}}{(x_i-x_j)}}}=\sum\limits_{i=0}^{n}{y_i\prod\limits_{j\not ={i}}\frac{x-x_j}{x_i-x_j}}
$$

即

$$
A(x)=\sum\limits_{i=0}^{n}{y_i\prod\limits_{j\not ={i}}\frac{x-x_j}{x_i-x_j}}
$$

在连乘式中， $0\sim n$ 除去 $i$ 后共有 $n$ 个数，故一共会乘 $n$ 次，每次都会乘上一个关于 $x$ 的一次多项式，故最终结果为 $n$ 次多项式，求和式则是 $n+1$ 个 $n$ 次多项式相加，结果仍是 $n$ 次多项式。\
这样，我们就能在 $O(n^2)$ 的时间内计算出 $A(x)$ 的各项系数，从而得到它的表达式。\
如果题目只要求 $A(k)$ 的值，其中 $k$ 是一个常数，那么我们只需要把上述公式中的 $x$ 替换成 $k$ 即可。注意： $x_i,y_i(0\le i\le n)$ 都是常数，是已知量。\
如果 $x_i=ai+b$ ，其中 $a,b$ 是一个常数，那么我们可以在 $O(n)$ 的时间内求出 $A(k)$ 的值。考虑多项式 $B(x)=A(ax+b)$ ，那么 $A(x_i)=B(i)$ ，即我们已知 $B(0),B(1),...,B(n)$ 的值，接下来要求 $B(m)$ ，其中 $k=am+b$ 。\
我们从式子入手，做一些转化：

$$
B(m)=\sum\limits_{i=0}^{n}{B(i)\prod\limits_{j\not ={i}}\frac{m-j}{i-j}}
$$

$$
C_k=\prod\limits_{i=0}^k(m-i),D_k=\prod\limits_{i=k}^n(m-i)
$$

$$
B(m)=\sum\limits_{i=0}^{n}{B(i)\frac{C_{i-1}D_{i+1}}{(-1)^{n-i}i!(n-i)!}}
$$

$O(n)$ 预处理 $C,D$ 以及阶乘，然后我们就可以 $O(1)$ 计算求和式的每一项，从而做到 $O(n)$ 求 $B(m)$ 的值。

习题：\
[【模板】拉格朗日插值](https://www.luogu.com.cn/problem/P4781)\
[The Sum of the k-th Powers](https://codeforces.com/contest/622/problem/F)\
[涂色（T2，题目见下发的包）](http://yalioj.yali.edu.cn/contest/223)
