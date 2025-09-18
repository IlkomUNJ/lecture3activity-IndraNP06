#include <iostream>
#include "Seller.h"
#include "Bank.h"

int main() {
    Bank bankUtama;
    BankCustomer akunBudi(987654, "Budi", 500000.0);
    BankCustomer akunAni(123456, "Ani", 1000000.0);
    bankUtama.addAccount(akunBudi);
    bankUtama.addAccount(akunAni);

    std::cout << ">>> Kondisi Awal Akun di Bank <<<\n";
    bankUtama.displayAllAccounts();

    Seller tokoBudi(101, "Toko Budi Jaya", akunBudi.getId());
    Item buku(1, "Buku Tulis", 50, 5000.0);
    Item pensil(2, "Pensil 2B", 100, 2500.0);
    tokoBudi.addItemToStock(buku);
    tokoBudi.addItemToStock(pensil);
    tokoBudi.displayStock();

    std::cout << "\n>> Mengupdate harga dan stok pensil (ID: 2)...\n" << std::endl;
    Item* itemToUpdate = tokoBudi.findItemById(2); 
    if (itemToUpdate != nullptr) {
        itemToUpdate->setQuantity(80);
        itemToUpdate->setPrice(2700.0); 
        std::cout << "Notifikasi: Item dengan ID 2 telah diperbarui." << std::endl;
    } else {
        std::cout << "Error: Item dengan ID 2 tidak ditemukan." << std::endl;
    }

    tokoBudi.displayStock();

    double totalBelanja = 5 * buku.getPrice(); 
    std::cout << ">>> Memproses Pembayaran dari Ani ke Budi sebesar Rp" << totalBelanja << " <<<\n";
    bankUtama.processTransfer(akunAni.getId(), akunBudi.getId(), totalBelanja);

    std::cout << "\n>>> Kondisi Akhir Akun di Bank <<<\n";
    bankUtama.displayAllAccounts();

    return 0;
}