/*
Trucks
Warehouses

//stdin

6 - (no of trucks)
1 4 2 6 4 9 - (position of each truck)
4 - (no of warehouses)
3 2 - (pos and capacity of warehouses 1)
5 1 - (pos and capacity of warehouses 2)
-1 1 - (pos and capacity of warehouses 3)
7 2 - (pos and capacity of warehouses 4)

//stdout
**find the minimum of total distance to park every truck in any warehouse.

//constraints

Truck {
    int id;
    int position;
}

Warehouse {
    int position;
    int capacity;
}

void readTrucks(Truck * trucks, int size);
void readWarehouses(Warehouse * warehouses, int size);
void sortTrucks(Truck * trucks, int size);
void sortWarehouses(Warehouse * warehouses, int size);
int calculateMinimumDistance(Truck * trucks, int trucks_size, Warehouse * warehouses, int warehouses_size);


*/
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    int position;
} Truck;

typedef struct
{
    int position;
    int capacity;
} Warehouse;

void readTrucks(Truck *trucks, int size)
{
    for (int i = 0; i < size; i++)
    {
        trucks[i].id = i + 1;
        scanf("%d", &(trucks[i].position));
    }
    return;
}

void readWarehouses(Warehouse *warehouses, int size)
{
    for (int i = 0; i < size; i++)
    {
        scanf("%d %d", &(warehouses[i].position), &(warehouses[i].capacity));
    }
    return;
}

int compareTrucks(const void *t1, const void *t2)
{
    Truck *a = (Truck *)t1;
    Truck *b = (Truck *)t2;
    return a->position - b->position;
}

void sortTrucks(Truck *trucks, int size)
{
    qsort(trucks, size, sizeof(Truck), compareTrucks);
    return;
}

int compareWarehouses(const void *w1, const void *w2)
{
    Warehouse *a = (Warehouse *)w1;
    Warehouse *b = (Warehouse *)w2;
    return a->position - b->position;
}

void sortWarehouses(Warehouse *warehouses, int size)
{
    qsort(warehouses, size, sizeof(Warehouse), compareWarehouses);
    return;
}

int calculateMinimumDistance(Truck *trucks, int t, Warehouse *warehouses, int w)
{
    int totalDistance = 0;
    int j = 0;
    for (int i = 0; i < w; i++)
    {
        while (j < t)
        {
            if (warehouses[i].capacity)
            {
                int d = abs(warehouses[i].position - trucks[j].position);
                // printf("Truck id: %d at position: %d will be parked in warehouse at position: %d\n", trucks[j].id, trucks[j].position, warehouses[i].position);
                totalDistance += d;
                warehouses[i].capacity--;
                j++;
                continue;
            }
            break;
        }
    }

    return totalDistance;
}

int main()
{
    int t, w;
    scanf("%d", &t);
    Truck *trucks = (Truck *)malloc(sizeof(Truck) * t);
    readTrucks(trucks, t);
    scanf("%d", &w);
    Warehouse *warehouses = (Warehouse *)malloc(sizeof(Warehouse) * w);
    readWarehouses(warehouses, w);
    sortTrucks(trucks, t);
    sortWarehouses(warehouses, w);
    int temp = calculateMinimumDistance(trucks, t, warehouses, w);
    printf("%d", temp);
    return 0;
}