/**
 * @mainpage Documentation circular queues
 * 
 * @section Introduction
 * This project from structur data
 * this project use structur data queues. Implements circular arrays.
 * 
 * @section Operations
 * - en queues for insert elements into queues
 * - de queues for delete elements from queues
 * - show data / display 
 * 
 * @section How to use 
 * 1. Insert 
 * 2. Delete
 * 3. Display
 * 4. Exit 
 * 
 * @author yProfile 
 * - Nama   : Alfilla Deo Ramadanu
 * - Nim    : 20240140210
 * - Kelas  : E
 * 
 * @brief 
 * @version 0.1
 * @date 2025-06-23
 * 
 * @copyright Gibran@umy.ac.id (c) 2025
 * 
 */


#include <iostream>
using namespace std;

/**
 * @class Queues
 * @brief This class is for operation queues 
 * 
 */

class Queues {
private: 
    int FRONT; /// private variable front for indicate first element 
    int REAR; /// private varibale raer for indicate the last element 
    int max = 5; /// private varibale max for maximum capasity of element
    int queue_array[5]; /// private variable queue_array for to store elements

public:
    /**
     * @brief Construct a new Queues object
     * set default queues null
     * with front = -1 and rear = -1
     */
    Queues() {
        FRONT = -1;
        REAR = -1;
    }
    /**
     * @brief method for entering data into a queue
     * 
     */


    /**
     * @brief Menambahkan elemen ke dalam antrian (enqueue).
     * 
     * Fungsi ini meminta pengguna untuk memasukkan sebuah angka.
     * Kemudian memeriksa apakah antrian penuh (overflow).
     * Jika tidak penuh, elemen ditambahkan ke posisi REAR dalam array.
     * 
     * Jika antrian masih kosong, maka FRONT dan REAR di-set ke 0.
     * Jika REAR sudah berada di akhir array, maka kembali ke indeks 0 (circular).
     */
    void insert() {
        int num;
        cout <<"Enter a number :";
        cin >> num;
        cout << endl;
    // Cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1))
        {
            cout << "\nQueue overflow\n";
            return;
        }
    
    // cek apakah antrian kosong
    if (FRONT == -1)
    {
        FRONT = 0;
        REAR = 0;
    }

    else
    {
        // jika REAR berada di posisi terakhir array, kembali ke awal array
        if (REAR == max -1)
            REAR = 0;
        else 
            REAR = REAR + 1;
    }
    queue_array[REAR] = num;
    }

     /**
     * @brief Menghapus elemen dari antrian (dequeue).
     * 
     * Fungsi ini menghapus elemen dari posisi FRONT dalam antrian.
     * Jika antrian kosong (FRONT == -1), maka akan muncul pesan underflow.
     * 
     * Jika hanya ada satu elemen (FRONT == REAR), maka antrian akan di-reset ke kosong.
     * Jika tidak, maka posisi FRONT akan digeser maju satu indeks secara melingkar.
     */
    void remove ()
    {
        // cek jika antrian hanya memiliki satu elemen 
        if (FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
        else 
        {
            // jika elemen yang dihapus berada di posisi terakhir array, kembali ke awal array 
            if (FRONT == max - 1)
                FRONT = 0;
            else 
                FRONT = FRONT + 1;
        }
    }

    /**
     * @brief Menampilkan semua elemen yang ada di dalam antrian
     * 
     * Fungsi ini mencetak elemen-elemen dari posisi FRONT hingga REAR
     * pada antrian melingkar (circular queue). Fungsi menangani dua kondisi:
     * - Jika elemen tersimpan secara berurutan (FRONT <= REAR),
     *   maka dicetak dari FRONT hingga REAR
     * - Jika elemen tersimpan secara melingkar (FRONT > REAR),
     *   maka dicetak dari FRONT ke akhir array, lalu dari awal array ke REAR
     * 
     * Jika antrian kosong (FRONT == -1), maka akan menampilkan pesan
     * "Queue is empty"
     */
void display();

    void display() {
        int FRONT_position = FRONT; /// posisi variabel FRONT di depan
        int REAR_position = REAR; /// posisi variabel REAR di belakang

        // cek apakah antrian kosong
        if (FRONT == -1)
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << "\nElements in the queue are.....\n";

        // jika Front_position <= REAR_position, iterasi dari front hingga array 

        if (FRONT_position <= REAR_position)
        {
            while (FRONT_position <= REAR_position)
            {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
        FRONT_position = 0;

            // iterasi dari awal array hingga REAR
            while (FRONT_position <= REAR_position) {
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }
            cout << endl;
        }
    }
};

    /**
     * @brief Fungsi utama untuk menjalankan program antrian circular (circular queue).
     * 
     * Fungsi ini menampilkan menu kepada pengguna untuk memilih:
     * - Menambahkan data ke antrian (Insert)
     * - Menghapus data dari antrian (Delete)
     * - Menampilkan isi antrian (Display)
     * - Keluar dari program (Exit)
     * 
     * Fungsi ini terus berjalan dalam loop hingga pengguna memilih keluar
     * 
     * @return int Mengembalikan nilai 0 saat program selesai dijalankan
     */
int main()
{
    Queues q;
    char ch;

    while (true)
    {
        try 
        {
            cout << "Menu" << endl;
            cout << "1. Implement insert operation" << endl;
            cout << "2. Implement delete operation" << endl;
            cout << "3. Display values" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice (1-4): ";
            cin >>  ch ;
            cout << endl;

            switch (ch)
            {
            case '1':
            {

                q.insert();
                break;
            }
            case '2':
            {
                q.remove();
                break;
            }
            case '3':
            {
                q.display();
                break;
            }
            case '4':
            {
                return 0;
            }
            default: 
            {
                cout << "Invalid option!!" << endl;
                break;
            }
            }
        }
        catch (exception &e)
        {
            cout << "Check for the values entered." << endl;
        }
    }
}
            
        
    
      