![Alt text](banner.png)


# What is PIOT?
PIOT is a framework support PHP Control mainboards as: Arduino, Atmega2560, Esp32, Esp8266 ...etc.
# How to use? 
You can download this library after that upload to library of arduino library. Next step you need add this

   #include <PIOT.h>
   PIOT piot;
   void setup() {
   // Khởi tạo giao tiếp Serial với tốc độ 9600 baud
   Serial.begin(9600);
   piot.begin();
   }

   void loop() {
   // Kiểm tra nếu có dữ liệu từ cổng Serial
   piot.listen();
   }

# Don't forget 
Don't forget close Arduino IDE after upload successfully. Because it can have problem about permission while PHP connect.

# PHP 

Visit here https://github.com/steveleetn91/php-PIOT
