# $\text{DGF}$ 简介 $\text{Singulet31258}$

## $\text{Dirichlet Convolution,DC}$

$$
h=f\ast g\iff h(n)=\sum_{d\mid n}f(d)g(\frac{n}{d})
$$

$h$ 是 $f,g$ 的狄利克雷卷积 $DC$ 。

$$
f\ast g=g\ast f
$$

$$
(f\ast g)\ast h=f\ast(g\ast h)
$$

$$
(f+g)\ast h=f\ast h+g\ast h
$$

$$
f\ast g\iff f\ast h=g\ast h,h(1)\ne 0
$$

$MF=\text{Multiplicative Function}$ ，积性函数。

$$
f^{a+b}=f^a\ast f^b,f^0=\varepsilon
$$

$$
\varepsilon(n)=\begin{cases}
    1,n=1\\
    0,n\ne 1
\end{cases}
$$

$$
f=MF,g=MF\Rightarrow f\ast g=MF
$$

$$
f=MF\iff f^{-1}=MF
$$

记 $DGF(f)$ 表示数论函数 $f$ 的 $DGF$ ，默认以 $x$ 为自变量， $\mathbb{P}$ 表示全体质数的集合。

$$
DGF(f)DGF(g)=DGF(f\ast g)
$$

$$
DGF(f)=\sum_{i=1}^\infty\frac{f(i)}{i^x}
$$

$$
f=MF\iff DGF(f)=\prod_{p\in\mathbb{P}}\sum_{i=0}^\infty\frac{f(p^i)}{p^{ix}}
$$

记 $\varphi$ 表示欧拉函数， $\zeta$ 表示黎曼函数， $\mu$ 表示莫比乌斯函数。

$$
I_k(n)=n^k,\sigma_k(n)=\sum_{d\mid n}d^k=(I_k\ast 1)(n)
$$

$$
DGF(I_k)=\zeta(x-k)
$$

$$
DGF(\varphi)=\frac{\zeta(x-1)}{\zeta(x)}
$$

$$
DGF(\mu)=\frac{1}{\zeta(x)}
$$

$$
DGF(\sigma_k)=\zeta(x-k)\zeta(x)
$$

$$
\varphi(n)=(I_1\ast\mu)(n)=\sum_{d\mid n}d\mu(\frac{n}{d})
$$

## $\text{DC}$ 的应用

### $\text{Mobius Inversion,MI}$

$$
f(n)=\sum_{d\mid n}g(d)\iff g(n)=\sum_{d\mid n}f(d)\mu(\frac{n}{d})
$$

其中 $f,g$ 为数论函数。 $f$ 是 $g$ 的莫比乌斯变换 $MT$ ， $g$ 是 $f$ 的莫比乌斯反演 $MI$ 。显然， $f=g\ast 1$ ， $g=f\ast\mu$ 。

$MI$ 的其他形式（设 $t$ 是一个完全积性函数且 $t(1)=1$ ）：

$$
f(n)=\sum_{n\mid d}g(d)\iff g(n)=\sum_{n\mid d}f(d)\mu(\frac{d}{n})
$$

$$
f(n)=\sum_{i=1}^nt(i)g(\lfloor\frac{n}{i}\rfloor)\iff g(n)=\sum_{i=1}^n\mu(i)t(i)f(\lfloor\frac{n}{i}\rfloor)
$$

### 杜教筛

给定数论函数 $f$ ，求 $s(f,n)=\sum_{i=1}^nf(i)$ 。

$$
s(f\ast g,n)=\sum_{i=1}^ng(i)s(f,\lfloor\frac{n}{i}\rfloor)
$$

$$
g(1)s(f,n)=s(f\ast g,n)-\sum_{i=2}^ng(i)s(f,\lfloor\frac{n}{i}\rfloor)
$$

其中 $g$ 是数论函数。设 $T(f,n)$ 表示计算 $s(f,n)$ 所需时间，设集合 $\mathbb{A}(n)=\set{\lfloor\frac{n}{k}\rfloor\mid 2\le k\le n,k\in\mathbb{Z}}$ 。

$$
T(f,n)=T(f\ast g,n)+O(\sqrt{n})T(g,n)+\sum_{i\in\mathbb{A}(n)}{T(f,i)}
$$

显然，若 $T(f\ast g,n),T(g,n)$ 很小（一般为 $O(1)$ ），那么 $T(f,n)$ 也会比较小（一般为 $o(n)$ ，即小于 $\Theta(n)$ ）。当 $T(f\ast g,n)=T(g,n)=O(1)$ 时，有：

$$
T(f,n)=O(\sqrt{n})+\sum_{i\in\mathbb{A}(n)}{T(f,i)}
$$

注意到 $\forall k\in\mathbb{A}(n),\mathbb{A}(k)\subset\mathbb{A}(n)$ ，因此我们可以按 $i$ 从小到大的顺序依次计算出所有的 $s(f,i),i\in\mathbb{A}(n)$ ，这样，我们就有：

$$
T(n)=O(\sqrt{n}+\mid\mathbb{A}(n)\mid)=O(\sqrt{n})
$$

显然， $\mid\mathbb{A}(n)\mid < 2\sqrt{n}$ 。那么总时间复杂度就是：

$$
\begin{aligned}
    O(\sqrt{n}+\sum_{i\in\mathbb{A}(n)}\sqrt{i})
    &=O(\sum_{i=1}^{\sqrt{n}}\sqrt{\frac{n}{i}})\\
    &=O(\int_{0}^{\sqrt{n}}{\sqrt{\frac{n}{x}}\mathrm{d}x})\\
    &=O(\sqrt{n}\int_{0}^{\sqrt{n}}{x^{-\frac{1}{2}}\mathrm{d}x})\\
    &=O(n^{\frac{3}{4}})
\end{aligned}
$$

第一个等号是将 $\mathbb{A}(n)$ 中最大的 $\sqrt{n}$ 个元素提取出来求和，由于 $\mathbb{A}(n)$ 总共只有不超过 $2\sqrt{n}$ 个元素，因此 $\sum_{i\in\mathbb{A}(n)}\sqrt{i} < 2\sum_{i=1}^{\sqrt{n}}\sqrt{\frac{n}{i}}$ （即把剩下的不超过 $\sqrt{n}$ 个元素放缩成最大的 $\sqrt{n}$ 个元素）。第二个等号则是把求和式转化成 $\sqrt{n}$ 个宽度为 $1$ 的矩形的面积和，然后放缩成积分形式，这个积分的值实际上比求和式的值要大，具体原因可以通过画图像来感知。最后求出这个积分的值为 $O(n^{\frac{3}{4}})$ ，故得出结论：当 $f\ast g,g$ 的前缀和都能 $O(1)$ 求时，用杜教筛求 $f$ 的前缀和的总时间复杂度也为 $O(n^{\frac{3}{4}})$ ，这比至少 $O(n)$ 的常规暴力算法要优许多。

当然，杜教筛还可以进一步优化。若用线性筛预处理前 $m$ 项，那么我们将只需求解 $\mathbb{A}(n)$ 中大于 $m$ 的那些项。即 $2\le k < \lfloor\frac{n}{m}\rfloor$ 的部分。此时的总时间复杂度为：

$$
\begin{aligned}
    O(m+\sum_{i=1}^{\frac{n}{m}}\sqrt{\frac{n}{i}})
    &=O(m+\int_{0}^{\frac{n}{m}}{\sqrt{\frac{n}{x}}\mathrm{d}x})\\
    &=O(m+\frac{n}{\sqrt{m}})
\end{aligned}
$$

当 $m=O(n^{\frac{2}{3}})$ 时，总时间复杂度为 $O(n^{\frac{2}{3}})$ 。

那么如何找到一个合适的 $g$ ，使得 $f\ast g,g$ 的前缀和均能快速求解呢？这个时候，你就可以考虑使用 $DGF$ 或者 $MI$ 进行变换。比如：

>$\alpha.$ 求 $s(\mu,n)$ 的值， $n < 2^{31}$

解：由于 $DGF(\mu)=\frac{1}{\zeta(x)},DGF(1)=\zeta(x),DGF(\varepsilon)=1$ ，故构造 $g=1$ 可得 $f\ast g=\varepsilon$ ，这 $2$ 个函数的前缀和都可以 $O(1)$ 求出。于是我们可以用杜教筛在 $O(n^{\frac{2}{3}})$ 的时间内解决本题。

>$\beta.$ 设数论函数 $f(n)=n^2\varphi(n)$ ，求 $s(f,n)$ 的值， $n\le 10^{10}$

解：显然， $f(n)$ 是一个积性函数，那么有：

$$
\begin{aligned}
    DGF(f)
    &=\prod_{p\in\mathbb{P}}{(1+\sum_{i=1}^{\infty}{\frac{p^{3i}-p^{3i-1}}{p^{ix}}})}\\
    &=\prod_{p\in\mathbb{P}}{(p^{-1}+(1-p^{-1})\sum_{i=0}^{\infty}{p^{(3-x)i}})}\\
    &=\prod_{p\in\mathbb{P}}{\frac{1-p^{2-x}}{1-p^{3-x}}}=\frac{\zeta(x-3)}{\zeta(x-2)}
\end{aligned}
$$

于是构造 $g=I_2$ ，那么 $DGF(g)=\zeta(x-2),DGF(f\ast g)=\zeta(x-3)=DGF(I_3)$ ，可得 $f\ast g=I_3$ 。而 $I_2(n)=n^2,I_3(n)=n^3$ ，这 $2$ 个函数的前缀和都可以 $O(1)$ 求出。于是我们可以用杜教筛在 $O(n^{\frac{2}{3}})$ 的时间内解决本题。

实际上， $DGF(n^k\varphi(n))=\frac{\zeta(x-k-1)}{\zeta(x-k)}$ ，这里取 $k=2$ 。

## 实战演练

>$\gamma.$ 给定 $n,m,k;1\le n,m\le 10^9;2\le k\le 2000;n,m,k\in\mathbb{Z}$ ，求有多少对 $(x,y)$ ，满足 $x\perp y;y\perp k;1\le x\le n;1\le y\le m;x,y\in\mathbb{Z}$ 。我们把满足这些条件的有序数对 $(x,y)$ 称为“美的数对”。
>例如，当 $n=2,m=6,k=10$ 时，有 $4$ 对“美的数对”： $(1,1);(1,3);(2,1);(2,3)$ 。
>[传送门](https://loj.ac/p/2085)

解：本题的答案为 $f(n,m,k)=\sum_{i=1}^n\sum_{j=1}^m\varepsilon(\gcd(i,j))\varepsilon(\gcd(j,k))$ ，接下来给它做一些变换：

$$
\begin{aligned}
    f(n,m,k)
    &=\sum_{j=1}^m\varepsilon(\gcd(j,k))\sum_{i=1}^n\varepsilon(\gcd(i,j))\\
    &=\sum_{j=1}^m\varepsilon(\gcd(j,k))\sum_{i=1}^n\sum_{d\mid i,d\mid j}\mu(d)\\
    &=\sum_{j=1}^m\varepsilon(\gcd(j,k))\sum_{d\mid j}^n\mu(d)\frac{n}{d}\\
    &=\sum_{d=1}^n\mu(d)\frac{n}{d}\varepsilon(\gcd(d,k))\sum_{j=1}^{\lfloor\frac{m}{d}\rfloor}\varepsilon(\gcd(j,k))\\
    &=\sum_{d=1}^n\mu(d)\frac{n}{d}\varepsilon(\gcd(d,k))g(\lfloor\frac{m}{d}\rfloor,k)
\end{aligned}
$$

$$
g(n,k)=\sum_{i=1}^n\varepsilon(\gcd(i,k))=\lfloor\frac{n}{k}\rfloor\varphi(k)+g(n\bmod k,k)
$$

$$
\begin{aligned}
    h(n,k)
    &=\sum_{i=1}^n\mu(i)\varepsilon(\gcd(i,k))\\
    &=\sum_{i=1}^n\varepsilon(\gcd(i,k))h(\lfloor\frac{n}{i}\rfloor,k)-\sum_{i=2}^n\varepsilon(\gcd(i,k))h(\lfloor\frac{n}{i}\rfloor,k)\\
    &=\sum_{i=1}^n\varepsilon(\gcd(i,k))\sum_{j=1}^{\lfloor\frac{n}{i}\rfloor}\mu(j)\varepsilon(\gcd(j,k))-\sum_{i=2}^n\varepsilon(\gcd(i,k))h(\lfloor\frac{n}{i}\rfloor,k)\\
    &=\sum_{i=1}^n\sum_{j=1}^{\lfloor\frac{n}{i}\rfloor}\mu(j)\varepsilon(\gcd(ij,k))-\sum_{i=2}^n\varepsilon(\gcd(i,k))h(\lfloor\frac{n}{i}\rfloor,k)\\
    &=\sum_{i=1}^n\varepsilon(\gcd(i,k))\varepsilon(i)-\sum_{i=2}^n\varepsilon(\gcd(i,k))h(\lfloor\frac{n}{i}\rfloor,k)\\
    &=1-\sum_{i=2}^n\varepsilon(\gcd(i,k))h(\lfloor\frac{n}{i}\rfloor,k)
\end{aligned}
$$

然后我们用 $\frac{n}{d},\frac{m}{d}$ 进行 $2$ 维数论分块，对于每一个块（假定块的左右边界分别为 $l,r$ ），求出 $h(r,k)-h(l-1,k)$ 即可。对于 $h(n,k)$ ，用杜教筛求即可。注意到 $l-1,r$ 要么属于 $\mathbb{A}(n)$ ，要么属于 $\mathbb{A}(m)$ ，因此只需杜教筛求 $h(n,k),h(m,k)$ 即可。时间复杂度为 $O(n^{\frac{2}{3}}+m^{\frac{2}{3}}+k\log{k})$ （预处理 $g(n,k),0\le n < k$ 以及 $\varphi(k)$ 需要 $O(k\log{k})$ 的时间）。

>$\delta.$ 给定 $n,p;n\le 10^{10};5\times 10^8 < p < 1.1\times 10^9;p\in\mathbb{P};n\in\mathbb{Z}$ ，设数论函数 $f$ 满足：
>
>$$
>f(n)=\sum_{i=1}^n\sum_{j=1}^nij\gcd(i,j)
>$$
>
>求 $f(n)\bmod p$ 的值。
>[传送门](https://www.luogu.com.cn/problem/P3768)

解：枚举 $d=\gcd(i,j)$ ，显然， $1\le d\le n$ ，于是有：

$$
\begin{aligned}
    f(n)
    &=\sum_{d=1}^n\sum_{i=1}^{\lfloor\frac{n}{d}\rfloor}\sum_{j=1}^{\lfloor\frac{n}{d}\rfloor}ijd^3[i\perp j]\\
    &=\sum_{d=1}^nd^3\sum_{i=1}^{\lfloor\frac{n}{d}\rfloor}i\sum_{j=1}^{\lfloor\frac{n}{d}\rfloor}j[i\perp j]\\
    &=\sum_{d=1}^nd^3\sum_{i=1}^{\lfloor\frac{n}{d}\rfloor}i\sum_{j=1}^{\lfloor\frac{n}{d}\rfloor}j\sum_{k\mid i,k\mid j}\mu(k)\\
    &=\sum_{d=1}^nd^3\sum_{i=1}^{\lfloor\frac{n}{d}\rfloor}i\sum_{j\mid i}j\mu(j)A_1(\lfloor\frac{n}{dj}\rfloor)\\
    &=\sum_{d=1}^nd^3B(\lfloor\frac{n}{d}\rfloor)
\end{aligned}
$$

$$
A_k(n)=\sum_{i=1}^ni^k,B(n)=\sum_{i=1}^{n}\mu(i)i^2A_3(\lfloor\frac{n}{i}\rfloor)
$$

$$
A_3(n)=\sum_{i=1}^{n}i^2B(\lfloor\frac{n}{i}\rfloor),B(n)=A_3(n)-\sum_{i=2}^{n}i^2B(\lfloor\frac{n}{i}\rfloor)
$$

容易发现，上述式子中的最后一个等式与杜教筛的标准形式非常相似。实际上， $A_k$ 就是 $I_k$ 的前缀和，因此若把该式看作杜教筛的标准形式，那么这里的 $f\ast g=I_3,g=I_2$。那么 $f$ 是什么呢？如果你有仔细阅读本篇 $\text{PDF}$ 的话，你会发现，这里的 $f$ 其实就是 $\beta.$ 所提到的那个数论函数 $f$ ！因此， $B(n)=\sum_{i=1}^ni^2\varphi(i)$ ，可以用杜教筛在 $O(n^{\frac{2}{3}})$ 的时间内求出。

$A_3$ 关于 $B$ 的表达式是通过 $MI$ 得到的，这里完美体现了 $MI$ 的强大之处。

对于 $f(n)$ ，我们用 $\frac{n}{d}$ 进行 $1$ 维数论分块，对于每个块，都要计算一次 $A_3(r)-A_3(l-1)$ 与 $B(k)$ ，其中 $k\in\mathbb{A}(n)$ 。由于我们在杜教筛计算 $B(n)$ 的同时已经计算出了所有的 $B(k),k\in\mathbb{A}(n)$ ，故我们可以在 $O(\sqrt{n})$ 的时间内求出 $f(n)$ 的值。

总时间复杂度为 $O(n^{\frac{2}{3}})$ ，注意到本题的模数 $p$ 在输入以后就不会再变了，故我们可以模仿编译器用 $BR$ 等技术优化取模操作，可显著降低本题常数。

>本题式子的另一种推导方法（无需使用 $MI$ ）：
>
>$$
>\begin{aligned}
>   f(n)
>   &=\sum_{i=1}^n\sum_{j=1}^nij\gcd(i,j)\\
>   &=\sum_{d=1}^n\sum_{i=1}^{\lfloor\frac{n}{d}\rfloor}\sum_{j=1}^{\lfloor\frac{n}{d}\rfloor}ijd^3[i\perp j]\\
>   &=\sum_{d=1}^nd^3\sum_{i=1}^{\lfloor\frac{n}{d}\rfloor}i\sum_{j=1}^{\lfloor\frac{n}{d}\rfloor}j[i\perp j]\\
>   &=\sum_{d=1}^nd^3(2\sum_{i=2}^{\lfloor\frac{n}{d}\rfloor}i\sum_{j=1}^{i-1}j[i\perp j]+1)\\
>   &=\sum_{d=1}^nd^3(2\sum_{i=2}^{\lfloor\frac{n}{d}\rfloor}i\frac{i\varphi(i)}{2}+1)\\
>   &=\sum_{d=1}^nd^3\sum_{i=1}^{\lfloor\frac{n}{d}\rfloor}i^2\varphi(i)\\
>   &=\sum_{d=1}^nd^3B(\lfloor\frac{n}{d}\rfloor)
>\end{aligned}
>$$

这里就直接推出了 $B(n)$ 是 $n^2\varphi(n)$ 的前缀和，方便又快捷。

推导依据：显然，交换 $i,j$ 的值不会影响 $ij[i\perp j]$ 的值，因此只需求 $j < i$ 与 $j=i$ 的部分。而 $j > i$ 的部分与 $j < i$ 的部分显然相等。

$j < i$ 的部分相当于求小于 $i$ 的所有与 $i$ 互质的正整数的和，容易证明，这个和在 $i>1$ 时为 $\frac{i\varphi(i)}{2}$ ，因为与 $i$ 互质的数 $j,i-j$ 一定成对出现，平均值为 $\frac{i}{2}$ ，而一共有 $\varphi(i)$ 个这样的数对。而当 $i=1$ 时，这一部分为 $0$ ，故可以忽略掉。

$j=i$ 的部分有 $[i\perp i]$ ，它仅当 $i=1$ 时取 $1$ ，否则取 $0$ ，故这部分的和必为 $1$ 。

而 $i^2\varphi(i)$ 在 $i=1$ 时刚好取 $1$ ，所以在把 $2$ 提到求和式中消去分母 $2$ 后， $1$ 可以消掉，然后求和式由从 $2$ 开始转为从 $1$ 开始，这样就得到了一个前缀和的形式。

>注：本题实际上存在一个时间复杂度为 $O(\frac{n^{\frac{2}{3}}}{\log{n}})$ 的最优解法，这里暂不作详解： [洛谷P3768最优解法代码参考](https://www.luogu.com.cn/record/99461213)

## 习题

[动态几何问题](https://loj.ac/p/509)

[Misaka Network 与求和](https://loj.ac/p/572)

[幽灵乐团](https://loj.ac/p/6693)

[简单的最大公约数](https://loj.ac/p/6491)

[Stupid GCD](https://loj.ac/p/6686)

[Stupid Product](https://loj.ac/p/6714)

[性能优化 I](https://loj.ac/p/6241)
