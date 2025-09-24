#include <stdio.h>
#define MAX 100  // kuyruk boyutu

int queue[MAX];
int front = -1, rear = -1;

// enqueue: kuyruğa eleman ekle
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Kuyruk dolu!\n");
    } else {
        if (front == -1) front = 0; // ilk eleman
        queue[++rear] = value;
        printf("%d eklendi.\n", value);
    }
}

// dequeue: kuyruktan eleman çıkar
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Kuyruk bos!\n");
    } else {
        printf("%d cikartildi.\n", queue[front++]);
        if (front > rear) front = rear = -1; // kuyruk boşaltıldı
    }
}

// peek: en öndeki elemanı göster
void peek() {
    if (front == -1) {
        printf("Kuyruk bos!\n");
    } else {
        printf("En ondeki eleman: %d\n", queue[front]);
    }
}

// kuyrugu yazdir
void display() {
    if (front == -1) {
        printf("Kuyruk bos!\n");
    } else {
        printf("Kuyruk: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Cikis\n");
        printf("Seciminizi yapin: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Eklenecek sayiyi girin: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Gecersiz secim!\n");
        }
    }
}
