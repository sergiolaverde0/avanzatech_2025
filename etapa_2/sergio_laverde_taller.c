#include <stdio.h>
#include <string.h>

#define MAX_PERSONAS 50
#define MAX_AMISTADES 500

// Función auxiliar para verificar si dos personas son amigas
// Retorna 1 si persona_a y persona_b son amigas, 0 en caso contrario
int son_amigos(const int amistades[][2], int m, int persona_a, int persona_b)
{
    for (int i = 0; i < m; i++) {
        if (amistades[i][0] == persona_a) {
            // Check in one direction
            if (amistades[i][1] == persona_b) {
                return 1;
            }
        } else if (amistades[i][0] == persona_b) {
            // Check in the opposite direction
            if (amistades[i][1] == persona_a) {
                return 1;
            }
        }
    }

    return 0;
}

// Función auxiliar para obtener la lista de amigos de una persona
// Almacena los IDs de amigos en el arreglo amigos y retorna el conteo
int obtener_amigos(const int amistades[][2], int m, int persona, int amigos[])
{
    int conteo = 0;
    for (int i = 0, j = 0; i < m; i++) {
        if (amistades[i][0] == persona) {
            amigos[j++] = amistades[i][1];
            conteo++;
        } else if (amistades[i][1] == persona) {
            amigos[j++] = amistades[i][0];
            conteo++;
        }
    }

    return conteo;
}

// Función 1: Verificar si la relación es reflexiva
int es_reflexiva(int n, int amistades[][2], int m)
{
    for (int i = 0; i < n; i++) {
        // Check if someone is its owwn friend
        int self_steem = son_amigos(amistades, m, i, i);
        // If not, return 0
        if (!self_steem) {
            return 0;
        }
    }
    // If code reached this point, then everyone is its own friend
    return 1;
}

// Función 2: Verificar si la relación es simétrica
int es_simetrica(int n, int amistades[][2], int m)
{
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (son_amigos(amistades, m, i, j)) {
                // If two people are friends in one direction...
                int simetry = son_amigos(amistades, m, j, i);
                if (!simetry) {
                    // But not in the other, return 0
                    return 0;
                }
            }
        }
    }
    // If code reached this point, then all friendships are symmetric
    return 1;
}

// Función 3: Encontrar si existe un clique de tamaño k
int encontrar_clique_de_tamano(int n, int amistades[][2], int m, int k)
{
    // Do nothing if k != 3
    if (k == 3) {
        // Verificar todas las posibles ternas
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k_persona = j + 1; k_persona < n; k_persona++) {
                    int i_j = son_amigos(amistades, m, i, j);
                    int j_k = son_amigos(amistades, m, j, k_persona);
                    int k_i = son_amigos(amistades, m, k_persona, i);
                    // If one group of three people satisfies the condition
                    // then return early
                    if (i_j && j_k && k_i) {
                        return 1;
                    }
                }
            }
        }
    }
    // If code reached this point, then no group of three people satisfies the
    // condition
    return 0;
}

// Función 4: Contar amigos mutuos entre dos personas
int contar_amigos_mutuos(int n, int amistades[][2], int m, int persona_a, int persona_b)
{
    int amigos_a[MAX_PERSONAS];
    int amigos_b[MAX_PERSONAS];
    int conteo_a = obtener_amigos(amistades, m, persona_a, amigos_a);
    int conteo_b = obtener_amigos(amistades, m, persona_b, amigos_b);

    int conteo_mutuo = 0;

    for (int i = 0; i < conteo_a; i++) {
        for (int j = 0; j < conteo_b; j++) {
            if (amigos_a[i] == amigos_b[j]) {
                conteo_mutuo++;
            }
        }
    }

    return conteo_mutuo;
}

// Función 5: Verificar si hay un camino desde inicio hasta fin
int puede_alcanzar(int n, int amistades[][2], int m, int inicio, int fin)
{
    static int visitado[MAX_PERSONAS];

    // If the function is called directly, clear `visitado` with zeroes
    // If this is a recursive call, do nothing to keep track of visited nodes
    static int en_progreso = 0;
    if (!en_progreso) {
        memset(visitado, 0, sizeof(visitado));
        en_progreso = 1;
    }

    if (inicio == fin) {
        en_progreso = 0;
        return 1;
    }

    visitado[inicio] = 1;

    int cola[MAX_PERSONAS];
    int conteo = obtener_amigos(amistades, m, inicio, cola);

    for (int i = 0; i < conteo; i++) {
        int amigo = cola[i];
        if (!visitado[amigo]) {
            if (puede_alcanzar(n, amistades, m, amigo, fin)) {
                en_progreso = 0;
                return 1;
            }
        }
    }

    return 0;
}

// Función 6: Verificar si todas las personas tienen grado par
int todos_grados_pares(int n, int amistades[][2], int m)
{
    int amigos[MAX_PERSONAS];

    for (int i = 0; i < n; i++) {
        int conteo = obtener_amigos(amistades, m, i, amigos);
        // If number of friends is odd, return 0 early
        if (conteo % 2 == 1) {
            return 0;
        }
    }
    // If this point is reached, all people have an even number of friends
    return 1;
}

int main()
{
    int n, m;

    printf("Ingrese número de personas y amistades: ");
    scanf("%d %d", &n, &m);

    int amistades[MAX_AMISTADES][2];

    printf("Ingrese amistades (persona_a persona_b):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &amistades[i][0], &amistades[i][1]);
    }

    // Probar todas las funciones
    printf("\n=== Resultados del Análisis ===\n");
    printf("Reflexiva: %s\n", es_reflexiva(n, amistades, m) ? "Sí" : "No");
    printf("Simétrica: %s\n", es_simetrica(n, amistades, m) ? "Sí" : "No");
    printf("Tiene clique triangular (tamaño 3): %s\n",
        encontrar_clique_de_tamano(n, amistades, m, 3) ? "Sí" : "No");

    // Probar amigos mutuos
    printf("\nIngrese dos personas para encontrar amigos mutuos: ");
    int a, b;
    scanf("%d %d", &a, &b);
    printf("Amigos mutuos entre %d y %d: %d\n",
        a, b, contar_amigos_mutuos(n, amistades, m, a, b));

    // Probar alcanzabilidad
    printf("\nIngrese persona de inicio y fin para verificar alcanzabilidad: ");
    int inicio, fin;
    scanf("%d %d", &inicio, &fin);
    printf("Se puede alcanzar desde %d hasta %d: %s\n",
        inicio, fin, puede_alcanzar(n, amistades, m, inicio, fin) ? "Sí" : "No");

    printf("\nTodos los grados pares: %s\n",
        todos_grados_pares(n, amistades, m) ? "Sí" : "No");

    return 0;
}
