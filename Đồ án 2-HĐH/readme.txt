Chạy syscalls:
sudo make menuconfig-> save->enter->exit
sudo make
sudo make modules_install 
sudo make install
Khởi động lại máy reboot
Biên dịch file test:
gcc testname.c -o testname
 gcc testid.c -o testid
 Chạy file test: ./testname 
./testid
Chạy Hook:
sudo make
insmod hook.ko
mở file kiểm tra
rmmod hook.ko
dmesg -wH