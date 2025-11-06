# Taller 2

## 1. Conjuntos, relaciones, y funciones con dados

### 1.1

$$
S = {1, 2, 3, 4, 5, 6}
T = {1, 2, 3}
$$

Dado que $T⊂S$, entonces:

$$
S ∪ T = S = {1, 2, 3, 4, 5, 6}
S ∩ T = T = {1, 2, 3}
S - T = {4, 5, 6}
$$

### 1.2

$$
R = {(x, y) | x ∈ S ∧ y ∈ S ∧ a + b = 7} = {(1, 6), (2, 5), (3, 4)}
$$

### 1.3

$$
f(x) = x \% 3, x ∈ S
$$

## 2. Teoría de grafos

### 2.1

Dado que la suma de dos números es par si ambos son par o si ambos son impar, se forman dos ciclos independientes, uno con los números pares y otro con los números pares.

### 2.2

Si se permite que un nodo se conecte con el mismo (porque la suma de un número con sigo mismo siempre es par) el grado de **todos** los vértices es de **3**.
Si se exige que los dados tomen valores distintos, el grado de **todos** los nodos es de **2**.

## 3. Pruebas estadísticas con M&Ms

### 3.1. Análisis de distribución de colores

#### 3.1.1. Chocolate

| Color    | Frecuencia real | Frecuencia teórica | Desviación |
| -------- | --------------- | ------------------ | ---------- |
| Marrón   | 21              | 21.71              | -0.71      |
| Amarillo | 9               | 23.38              | -14.38     |
| Rojo     | 9               | 21.71              | -12.71     |
| Naranja  | 58              | 33.40              | 24.6       |
| Verde    | 14              | 26.72              | -12.72     |
| Azul     | 56              | 40.08              | 15.92      |
| Total    | 167             | 167                | 0.02       |

#### 3.1.2. Maní

| Color    | Frecuencia real | Frecuencia teórica | Desviación |
| -------- | --------------- | ------------------ | ---------- |
| Marrón   | 5               | 8.64               | -3.64      |
| Amarillo | 23              | 10.80              | 12.2       |
| Rojo     | 5               | 8.64               | -3.64      |
| Naranja  | 22              | 16.56              | 5.44       |
| Verde    | 9               | 10.80              | -1.8       |
| Azul     | 8               | 16.56              | -8.56      |
| Total    | 72              | 72                 | 0.00       |

### 3.2. Compara tus datos personales con la distribución estándar

#### 3.2.1. Chocolate

$$
χ^2 = ∑\frac{(f-f_t)^2}{f_t}
χ^2 = \frac{(21-21.71)^2}{21.71} + \frac{(9-23.38)^2}{23.38} + \frac{(9-21.71)^2}{21.71} +
     \frac{(58-33.40)^2}{33.40} + \frac{(14-26.72)^2}{26.72} + \frac{(56-40.08)^2}{40.08}
χ^2 = 0.0232 + 8.8445 + 7.4410 + 18.1186 + 6.0553 + 6.3235
χ^2 = 46.8061
$$

Con 5 grados de libertad, el estadístico calculado de 46.8061 tiene una probabilidad de aparecer de prácticamente 0. Un valor crítico de 20.5150 equivale a una probabilidad del 0.1%, y el estadístico calculado es aún más alto. Se puede rechazar con total confianza la hipótesis nula, y decir que las bolsas de M&Ms de chocolate no siguen la distribución estándar proporcionada.

#### 3.2.2. Maní

$$
χ^2 = ∑\frac{(f-f_t)^2}{f_t}
χ^2 = \frac{(5-8.64)^2}{8.64} + \frac{(23-10.80)^2}{10.80} + \frac{(5-8.64)^2}{8.64} + \frac{(22-16.56)^2}{16.56} +
     \frac{(9-10.80)^2}{10.80} + \frac{(8-16.56)^2}{16.56}
χ^2 = 1.5335 + 13.7815 + 1.5335 + 1.7785 + 0.3 + 4.4247
χ^2 = 23.3517
$$

Con 5 grados de libertad, el estadístico calculado de 23.3517 tiene una probabilidad de ocurrir de **0.029%**. Por lo que es extremadamente improbable que las bolsas de M&Ms de maní sigan la distribución estándar proporcionada.

#### 3.2.3. Chocolate vs maní

| Color    | Chocolate | Maní | Total |
| -------- | --------- | ---- | ----- |
| Marrón   | 21        | 5    | 26    |
| Amarillo | 9         | 23   | 32    |
| Rojo     | 9         | 5    | 14    |
| Naranja  | 58        | 22   | 80    |
| Verde    | 14        | 9    | 23    |
| Azul     | 56        | 8    | 64    |
| Total    | 167       | 72   | 239   |

$$
χ^2 = ∑\frac{(f-f_t)^2}{f_t}
χ^2 = \frac{(21-(26*167/239))^2}{23*167/239} + \frac{(9-(32*167/239))^2}{32*167/239} + \frac{(9-(14*167/239))^2}{14*167/239} +
     \frac{(58-(80*167/239))^2}{80*167/239} + \frac{(14-(23*167/239))^2}{23*167/239} + \frac{(56-(64*167/239))^2}{64*167/239} +
     \frac{(5-(26*72/239))^2}{26*72/239} + \frac{(23-(32*72/239))^2}{32*72/239} + \frac{(5-(14*72/239))^2}{14*72/239} +
     \frac{(22-(80*72/239))^2}{80*72/239} + \frac{(9-(23*72/239))^2}{23*72/239} + \frac{(8-(64*72/239))^2}{64*72/239}
χ^2 = 0.4417 + 7.9824 + 0.0626 + 0.0789 + 0.2669 + 2.8454 + 1.0244 + 18.5147 + 0.1452 + 0.1831 + 0.6191 + 6.5998
χ^2 = 38.7641
$$

Con 5 grados de libertad, el estadístico calculado de 38.7641 tiene una probabilidad de ocurrir de prácticamente 0. Un valor crítico de 20.5150 equivale a una probabilidad del 0.1%, y el estadístico calculado es aún más alto. Se puede rechazar con total confianza la hipótesis nula, y decir que las bolsas de M&Ms de chocolate y las de maní tienen distribuciones de colores diferentes.

### 3.3 Comparación entre estudiantes

En comparación con Samuel, sus pruebas de chi-cuadrado no rechazan las hipótsis de que tanto los M&Ms de chocolate como los de maní siguen las distribuciones dadas, ni la hipótesis de que ambas variedades tienen idéntica distribución; sus estadísticos $χ^2$ son todos ellos inferiores al valor crítico al 5% de confianza para una distribución con 5 grados de libertad.

Vale la pena mencionar que no es posible que todas estas hipótesis sean ciertas al mismo tiempo: si ambas bolsas tienen idéntica distribución, no pueden tener las distribuciones asignadas porque estas son diferentes entre sí. Por lo menos uno de los resultados de Samuel debe ser un falso negativo.

## 4. Pruebas estadśiticas avanzadas con datos de dados

### 4.1. Prueba de hipótesis nula

Se registraron 11 resultados exitosos (parejas de daods que suman 7) en 60 experimentos (lanzamientos). La probabilidad de obtener 11 o más éxitos cuando la probabilidad de éxito es de 11/6 es:

$$
P(X >= 11) = 1 - P(X < 11) = 1 - \sum_{k=0}^{10} b(x, 60, 1/6)
P(X >= 11) = 1 - 0.292 = 0.708
$$

### 4.2. Prueba de chi-cuadrado

Se realizaron 60 nuevos lanzamientos de parejas de dados, con el siguiente resultado:

| Valor | Frecuencia real | Frecuencia teórica |
| ----- | --------------- | ------------------ |
| 2     | 4               | 5/3                |
| 3     | 2               | 10/3               |
| 4     | 9               | 5                  |
| 5     | 6               | 20/3               |
| 6     | 10              | 25/3               |
| 7     | 10              | 10                 |
| 8     | 5               | 25/3               |
| 9     | 5               | 20/3               |
| 10    | 3               | 5                  |
| 11    | 4               | 10/3               |
| 12    | 2               | 5/3                |
| Total | 60              | 60                 |

Se calcula el estadístico $χ^2$:

$$
χ^2 = ∑\frac{(f-f_t)^2}{f_t}
χ^2 = \frac{(4 - 5/3)^2}{5/3} + \frac{(2-10/3)^2}{10/3} + \frac{(9-5)^2}{5} + \frac{(6-20/3)^2}{20/3} + \frac{(10-25/3)^2}{25/3} + \frac{(10-10)^2}{10} +
     \frac{(5-25/3)^2}{25/3} + \frac{(5-20/3)^2}{20/3} + \frac{(3/5)}{5} + \frac{(4-10/3)^2}{10/3}+ \frac{(2-5/3)^2}{5/3}
χ^2 = 49/15 + 8/15 + 16/5 + 1/15 + 1/3 + 0 + 4/3 + 5/12 + 4/5 + 2/15 + 1/15
χ^2 = 203/20 = 10.15
$$

Con 10 grados de libertad y un intervalo de confianza del 5%, el valor crítico es de 18.3070. Dado que el estadístico calculado es **menor** que el valor crítico, no se rechaza la hipótesis nula, por lo que se concluye que los dados empleados en el experimento están balanceados.
