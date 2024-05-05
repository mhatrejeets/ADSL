#include<iostream>
using namespace std;

void hashFunctionWithoutReplacement(int arr[], int hashedArr[], int hashedKey) {
    for(int i = 0; i < 10; i++) {
        hashedArr[i] = -1;
    }
    for(int i = 0; i < 10; i++) {
        if(hashedArr[arr[i] % hashedKey] == -1) {
            hashedArr[arr[i] % hashedKey] = arr[i];
        } else {
            for(int j = 0; j < 10; j++) {
                if(hashedArr[j] == -1) {
                    hashedArr[j] = arr[i];
                    break;
                }
            }
        }
    }
}

void hashFunctionWithReplacement(int arr[], int hashedArr[], int hashedKey) {
    for(int i = 0; i <  10; i++) {
        hashedArr[i] = -1;
    }
    for(int i = 0; i < 10; i++) {
        int index = arr[i] % hashedKey;
        
        if(hashedArr[index] == -1) {
            hashedArr[index] = arr[i];
        } 

        else {
            int newIndex = (index + 1) % 10; // Linear probing
            while(hashedArr[newIndex] != -1) {
                newIndex = (newIndex + 1) % 10; // Move to the next index
            }
            hashedArr[newIndex] = arr[i];
        }
    }
}

int main() {
    cout << "Enter the hashKey: ";
    int hashKey;
    cin >> hashKey;

    int arr[10];
    cout << "\nEnter the elements of the array: ";
    for(int i = 0; i < 10; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    int hashArr[10];
    hashFunctionWithoutReplacement(arr, hashArr, hashKey);
    cout << "\nThe hashed Array without replacement is: ";
    for(int i = 0; i < 10; i++) {
        cout << hashArr[i] << " ";
    }

    int hashArr1[10];
    hashFunctionWithReplacement(arr, hashArr1, hashKey);
    cout << "\nThe hashed Array with replacement is: ";
    for(int i = 0; i < 10; i++) {
        cout << hashArr1[i] << " ";
    }

    return 0;
}
