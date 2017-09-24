#include <iostream>

#define ROAD '1'

using namespace std;

int is_x_cross(char **city, int N, int y, int x) {
    if (y == 0 || x == 0 || x == N - 1 || y == N - 1 || city[y][x] != ROAD) {
        return 0;
    }
    char c[8];
    // 0 1 2
    // 3 x 4
    // 5 6 7
    c[0] = city[y - 1][x - 1];
    c[1] = city[y - 1][x];
    c[2] = city[y - 1][x + 1];
    c[3] = city[y][x - 1];
    c[4] = city[y][x + 1];
    c[5] = city[y + 1][x - 1];
    c[6] = city[y + 1][x];
    c[7] = city[y + 1][x + 1];
    // diagonal cross
    if (
        c[0] == ROAD && c[1] != ROAD && c[2] == ROAD &&
        c[3] != ROAD &&                 c[4] != ROAD &&
        c[5] == ROAD && c[6] != ROAD && c[7] == ROAD
    ) {
        return 1;
    }
    // vertial cross
    if (
        c[0] != ROAD && c[1] == ROAD && c[2] != ROAD &&
        c[3] == ROAD &&                 c[4] == ROAD &&
        c[5] != ROAD && c[6] == ROAD && c[7] != ROAD
    ) {
        return 1;
    }
    return 0;
}

int is_t_cross(char **city, int N, int y, int x) {
    if (city[y][x] != ROAD) {
        return 0;
    }
    //  0  || ---
    // 1x1 || 1x1
    // 010 || 010
    if (y < N - 1 && x > 0 && x < N - 1) {
        if (
            city[y][x - 1]     == ROAD && city[y][x + 1] == ROAD &&
            city[y + 1][x - 1] != ROAD && city[y + 1][x] == ROAD &&
            city[y + 1][x + 1] != ROAD && (
                ( y > 0 && city[y - 1][x] != ROAD ) || y == 0
            )
        ) {
            return 1;
        }
    }
    // 010 || 010
    // 1x1 || 1x1
    //  0  || ---
    if (y > 0 && x > 0 && x < N - 1) {
        if (
            city[y][x - 1]     == ROAD && city[y][x + 1] == ROAD &&
            city[y - 1][x - 1] != ROAD && city[y - 1][x] == ROAD &&
            city[y - 1][x + 1] != ROAD && (
                ( y < N - 1 && city[y + 1][x] != ROAD ) || y == N - 1
            )
        ) {
            return 1;
        }
    }
    //  10 || |10
    // 0x1 || |x1
    //  10 || |10
    if (y > 0 && y < N - 1 && x < N - 1) {
        if (
            city[y - 1][x] == ROAD && city[y - 1][x + 1] != ROAD &&
                                      city[y][x + 1]     == ROAD &&
            city[y + 1][x] == ROAD && city[y + 1][x + 1] != ROAD && (
                ( x > 0 && city[y][x - 1] != ROAD ) || x == 0
            )
        ) {
            return 1;
        }
    }
    // 01  || 01|
    // 1x0 || 1x|
    // 01  || 01|
    if (y > 0 && y < N - 1 && x > 0) {
        if (
            city[y - 1][x - 1] != ROAD && city[y - 1][x] == ROAD &&
            city[y][x - 1]     == ROAD                           &&
            city[y + 1][x - 1] != ROAD && city[y + 1][x] == ROAD && (
                ( x < N - 1 && city[y][x + 1] != ROAD ) || x == N - 1
            )
        ) {
            return 1;
        }
    }
    // 101 || 101 || 001 || 100
    // 0x0 || 0x0 || 0x0 || 0x0
    // 100 || 001 || 101 || 101
    if (y > 0 && y < N - 1 && x > 0 && x < N - 1) {
        int diag_roads_count { 0 };
        if (city[y - 1][x - 1] == ROAD) { ++diag_roads_count; }
        if (city[y - 1][x + 1] == ROAD) { ++diag_roads_count; }
        if (city[y + 1][x - 1] == ROAD) { ++diag_roads_count; }
        if (city[y + 1][x + 1] == ROAD) { ++diag_roads_count; }
        if (
            city[y - 1][x] != ROAD && city[y][x - 1] != ROAD &&
            city[y][x + 1] != ROAD && city[y + 1][x] != ROAD &&
            diag_roads_count == 3
        ) {
            return 1;
        }
    }
    return 0;
}

int check_cage(char **city, int N, int y, int x) {
    if (is_x_cross(city, N, y, x)) {
        return 2;
    }
    if (is_t_cross(city, N, y, x)) {
        return 1;
    }
    return 0;
}

int main() {
    int N            { 0 };
    int x_crossroads { 0 };
    int t_crossroads { 0 };
    cin >> N;
    char **city = new char *[N];
    for (int i = 0; i < N; ++i) {
        city[i] = new char [N];
    }

    for (int i = 0; i < N * N; ++i) {
        cin >> city[i / N][i % N];
    }

    // cout << endl;
    // for (int j = 0; j < N; ++j) {
    //     for (int i = 0; i < N; ++i) {
    //         cout << city[j][i];
    //     }
    //     cout << endl;
    // }

    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < N; ++i) {
            switch (check_cage(city, N, j, i)) {
                case 2:
                    ++x_crossroads;
                    break;
                case 1:
                    ++t_crossroads;
                    break;
                default:
                    break;
            }
        }
    }

    cout << x_crossroads + t_crossroads << ' ' << t_crossroads << ' '
         << x_crossroads << endl;

    for (int i = 0; i < N; ++i) {
        delete [] city[i];
    }
    delete [] city;
    return 0;
}
