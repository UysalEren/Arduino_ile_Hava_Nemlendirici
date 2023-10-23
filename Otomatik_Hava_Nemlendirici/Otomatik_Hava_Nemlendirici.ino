#include <DHT.h>

#define DHTPIN 2    // DHT11 sensörünün bağlı olduğu pin
#define DHTTYPE DHT11  

DHT dht(DHTPIN, DHTTYPE);

const int relayPin = 10;  // Röle pin numarası
const int desiredHumidity = 45;  // Hedef nem oranı

void setup() {
  pinMode(relayPin, OUTPUT);
  dht.begin();
}

void loop() {
  float humidity = dht.readHumidity();

  if (!isnan(humidity)) {
    // Nem 
    if (humidity < desiredHumidity) {
      // Hedef nem oranının altındaysa nemlendiriciyi çalıştır
      digitalWrite(relayPin, HIGH);
    } else {
      // Hedef nem oranının üstündeyse nemlendiriciyi kapat
      digitalWrite(relayPin, LOW);
      // Bu işlemleri röle ile yapıyoruz 
    }
  } else {
    // Nem okunamazsa hata mesajı gönder
    Serial.println("Nem okunamıyor. Sensör hatası.");
  }

  delay(1000);  // 1 saniye bekle
}

//Kullandığımız hazır piezo kartının üzerindeki tuşu iptal etmeyi unutmayın !!!!!!
