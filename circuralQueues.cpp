/**
 * @mainpage Documentation Circular Queue
 * 
 * @section Introduction
 * Project ini merupakan project struktur data
 * menggunakan struktur data queues dengan pendekatan circular arrays.abort
 * 
 * @section Operations
 * - en queue for insert elements into queues
 * - de queue for delete element from queues
 * - show data / display data
 * 
 * @section How to use
 * 1. Insert
 * 2. Delete
 * 3. Display
 * 4. Exit
 * 
 * @author yProfil
 * - Nama   : Ridho faiq Ahmad
 * - NIM    : 20240140216
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
 * @class Queue
 * @brief This class is for operation queues
 * 
 */

class Queues 
{
private:
    int FRONT; /// private variable front for indicate first element 
    int REAR; /// private variable rear for indicate the last element
    int max = 5; /// private variable max for maximum capasity of element
    int queue_array[5]; /// private variable queue_array for

public:
    /**
     * @brief Construct a new Queues object
     * set default queues null
     * with front = -1 and rear = -1
     */
    Queues() 
    {
        FRONT = -1;
        REAR = -1;
    }

    /**
     * @brief method for entering data into a queue
     * 
     * 
     */
    void insert () {
        int num; /// variable num for indicate data type number
        cout << "Enter a number :"; /// enter your number
        cin >> num; /// enter number to variable num
        cout << endl;

        // Cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) /// check if the queue is full (both normal and circular)
        {
            cout << "\nQueue overflow\n"; /// display massage when queue is full
            return; /// indicate the program ended successfully
        }

        // Cek apakah antrian kosong
        if (FRONT == -1) /// If the queue is empty, initialize FRONT and REAR to 0
        {
            FRONT = 0;
            REAR = 0;
        }
        else
        {
            // Jika REAR berada di posisi terakhir array, kembali ke awal array
            if (REAR == max -1) /// If REAR reaches the end of the array, wrap it to the beginning
                REAR = 0;
            else
                REAR++; /// move REAR forward 
        }
        queue_array[REAR] = num; /// Store the new element at rear
    }

    /**
     * @brief /// method for removing data from queue
     * 
     */

    void remove () /// Check if the queue is empty
    {
        // Cek apakah antrian kosong
        if (FRONT == -1)
        {
            cout << "Queue underflow\n"; /// Nothing to delete
            return; /// indicate the program ended succesfully or return 0
        }
        cout << "\nThe element deleted from queue is :" << queue_array[FRONT] << "\n"; /// print the element that will be deleted

        // Cek jika antrian hanya memiliki satu elemen
        if (FRONT == REAR) /// if only one element exist, reset the queue to empty
        {
            FRONT = -1; 
            REAR = -1;
        }
        else
        {
            // Jika elemen yang di hapus berada di posisi terakhir array, kembali ke awal array
            if (FRONT == max - 1) /// If FRONT is at the end, wrap around to 0
                FRONT = 0;
            else    
                FRONT = FRONT + 1; /// Move FRONT one step forward
        }
    }
    
    /**
     * @brief method for display data into a queues
     * 
     */
    
    void display() /// Check if the queue is empty
    {
        int FRONT_position = FRONT; /// position variable FRONT in FRONT
        int REAR_position = REAR; /// position variable REAR ini REAR

        // Cek apakah antrian kosong
        if (FRONT == -1) 
        {
            cout << "Queue is empty\n"; /// Display this queue is empty
            return; /// indicate the program ended succesfully or return 0
        }

        cout << "\nElements in the queue are...\n"; /// print a massage before displaying the contens of the queue

        // Jika Front_position <= REAR_position, iterasu=i dari FRONT hingga REAR

        if (FRONT_position <= REAR_position) /// if queue is in linear order (no wrapping)
        {
            while (FRONT_position <= REAR_position)
            {
                cout << queue_array[FRONT_position] << "   ";
                FRONT_position++;
            }
            cout << endl;
        }
    }

};

/**
 * @brief Main function to run the program
 * 
 * @return int 
 */


int main()
{
    Queues q; /// Create an object of the Queues Class
    char ch; /// Variable to store user's menu selection

    /// Infinite loop to repeatedly show menu 
    while (true)
    {
        try
        {
            cout << "Menu" << endl;
            cout << "1. Implement insert operation" << endl;
            cout << "2. Implement delete operation" << endl;
            cout << "3. Display value" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice (1-4)";
            cin >> ch;
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
                }case '3':
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


