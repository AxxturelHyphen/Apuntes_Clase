### 1. ¿Para qué lo usamos en DSA?

En **análisis de algoritmos** comparamos funciones tipo:

- $T_1(n) = n \log n$
    
- $T_2(n) = n^2$
    
- $T_3(n) = 2^n$
    
- $T_4(n) = \log n$, etc.
    

Para saber cuál crece más rápido, miramos el límite:

					 $\lim_{n \to \infty} \frac{T_1(n)}{T_2(n)}​$

- Si el límite es **0** → $T_1(n)$ crece más lento → $T_1(n) \in o(T_2(n))$
    
- Si el límite es **∞** → $T_1(n)$ crece más rápido → $T_1(n) \in \omega(T_2(n))$
    
- Si el límite es **una constante $c>0$** → mismo orden → $T_1(n) \in \Theta(T_2(n))$
    

El problema: muchos límites son del tipo **∞/∞** o **0/0**.  
Ahí entra **L’Hôpital’s**.

---

### 2. Enunciado de L’Hôpital (versión simple)

Si:

- $\displaystyle \lim_{x \to a} f(x) = \lim_{x \to a} g(x) = 0$ **o** ambos son $\infty$
    
- $f$ y $g$ son derivables cerca de $a$
    
- $g'(x) \neq 0$ cerca de $a$
    

Entonces:

$\large{\lim_{x \to a} \frac{f(x)}{g(x)} = \lim_{x \to a} \frac{f'(x)}{g'(x)}}$

si este segundo límite existe (o es $\pm \infty$).

En DSA simplemente tratamos $n$ como real ($x$) y hacemos el límite cuando $x \to \infty$.

---

### 3. Ejemplos típicos DSA (muy rápidos)

#### Ejemplo 1: $\log n$ vs $n^\alpha$ (cualquier $\alpha>0$)

Compara $f(n) = \log n$ y $g(n) = n^\alpha$:

			$L = \lim_{n \to \infty} \frac{\log n}{n^\alpha}$

Es $\infty / \infty$. Aplico L’Hôpital:

- $f'(x) = \dfrac{1}{x}$
    
- $g'(x) = \alpha x^{\alpha-1}$
    

$L=lim⁡x→∞1/xαxα−1=lim⁡x→∞1αxα=0L = \lim_{x \to \infty} \frac{1/x}{\alpha x^{\alpha-1}} = \lim_{x \to \infty} \frac{1}{\alpha x^\alpha} = 0L=x→∞lim​αxα−11/x​=x→∞lim​αxα1​=0$

⇒ $\log n$ crece mucho más lento que $n^\alpha$  
⇒ $\log n \in o(n^\alpha)$

Traducción DSA: **cualquier $n^\alpha$ gana a $\log n$**.

---

#### Ejemplo 2: $n \log n$ vs $n^2$

L=lim⁡n→∞nlog⁡nn2=lim⁡n→∞log⁡nnL = \lim_{n \to \infty} \frac{n\log n}{n^2} = \lim_{n \to \infty} \frac{\log n}{n}L=n→∞lim​n2nlogn​=n→∞lim​nlogn​

Otra vez $\infty / \infty$:

- $f'(x) = 1/x$
    
- $g'(x) = 1$
    

L=lim⁡x→∞1/x1=0L = \lim_{x \to \infty} \frac{1/x}{1} = 0L=x→∞lim​11/x​=0

⇒ $n\log n \in o(n^2)$  
Traducción DSA: **$O(n \log n)$ es mejor (más rápido) que $O(n^2)$**.

---

#### Ejemplo 3: $n$ vs $2^n$

L=lim⁡n→∞n2nL = \lim_{n \to \infty} \frac{n}{2^n}L=n→∞lim​2nn​

Tipo $\infty / \infty$. Derivamos:

- $f'(x) = 1$
    
- $g'(x) = 2^x \ln 2$
    

L=lim⁡x→∞12xln⁡2=0L = \lim_{x \to \infty} \frac{1}{2^x \ln 2} = 0L=x→∞lim​2xln21​=0

⇒ $n \in o(2^n)$  
Traducción DSA: **cualquier exponencial $a^n$ revienta a cualquier polinomio $n^k$**.

---

### 4. Resumen mental rápido para DSA

Usando L’Hôpital (y estos patrones) te quedas con la jerarquía clásica de crecimiento:

log⁡n≪nα≪nαlog⁡kn≪an≪n!\log n \ll n^\alpha \ll n^\alpha \log^k n \ll a^n \ll n! logn≪nα≪nαlogkn≪an≪n!

- $\log n$ = muy lento (good complexity)
    
- $n$, $n \log n$, $n^2$, $n^3$… = polinómicos (normalito)
    
- $2^n$, $3^n$… = exponenciales (malo)
    
- $n!$ = peor todavía
    

Eso es exactamente lo que quieres para **Big-O / Big-Θ / Big-Ω** en análisis de algoritmos.