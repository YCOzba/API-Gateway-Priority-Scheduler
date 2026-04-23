RFC 9213 Uyumlu, Modüler API Gateway İstek Zamanlayıcısı
Bu proje, C dilinde geliştirilmiş, yüksek trafikli API Gateway sistemlerinde gelen istekleri (request) geliş sırasına göre değil, RFC 9213 Extensible HTTP Priorities standartlarına göre sıraya sokan ve işleyen bir zamanlayıcı (Priority Scheduler) simülasyonudur.

🚀 Projenin Temel Özellikleri
Min-Heap Algoritması: Kuyruktaki en acil isteği O(1) sürede bulur, yeni istek ekleme ve çıkarma işlemlerini O(log N) zaman karmaşıklığında gerçekleştirerek yüksek yük altında sistemin kilitlenmesini önler.

Sıfır Bellek Sızıntısı (Zero-Leak): İstek kuyruğu dinamik olarak genişletilir. Tüm işlemler tamamlandığında free_queue fonksiyonu ile işletim sisteminden alınan tüm RAM eksiksiz bir şekilde iade edilir.

RFC 9213 Uyumluluğu: Gelen HTTP başlıklarındaki (header) string yapıları ayrıştırılır. Aciliyet (urgency) değeri u=0 (en yüksek) ile u=7 (en düşük) arasında değerlendirilir.

Modüler Mimari: Sistem, Separation of Concerns (Sorumlulukların Ayrılığı) prensibine uygun olarak katmanlara ayrılmıştır.

🏗️ Yazılım Mimarisi
Sistem dört ana katmandan oluşmaktadır:

request.h (Ortak Veri Yapısı): Sistemdeki tüm modüllerin haberleştiği temel struct yapısıdır.

rfc9213_parser.c / .h (Ayrıştırıcı Katman): Gelen HTTP string verilerini analiz edip öncelik değerlerini (u) çözümleyen bağımsız modüldür.

priority_queue.c / .h (Algoritma Katmanı): Sadece bellek yönetimi ve Min-Heap ağaç dengesiyle ilgilenen motor katmanıdır.

main.c (Ana Kontrolcü): Modülleri koordine eden, verileri ayrıştırıcıdan alıp kuyruğa ileten merkezdir.

🤖 Yapay Zeka Kullanım Beyanı (AI Disclosure)
Bu projenin araştırma ve geliştirme sürecinde, üretken yapay zeka araçlarından yalnızca bir "yardımcı pilot" (co-pilot) ve mimari danışman olarak faydalanılmıştır.

Yapay Zekanın Kullanıldığı Alanlar:

Mimari Fikir Alışverişi: "Separation of Concerns" (Sorumlulukların Ayrılığı) prensibinin C dilinde nasıl en verimli şekilde uygulanabileceğine dair konsept tartışmaları.

Dokümantasyon ve Sunum: Slayt içeriklerinin hiyerarşik olarak düzenlenmesi ve bu README dosyasının profesyonel formatta hazırlanması.

Manuel Olarak Geliştirilen Alanlar:

Sistemin çekirdek algoritması olan Min-Heap (İkili Ağaç) matematiği.

C dilinin düşük seviyeli özellikleri olan pointer (işaretçi) aritmetiği ve bellek bloklarının (malloc, realloc, free) yönetimi.

Hata ayıklama (Debugging), GCC ile derleme süreçleri ve uç durum (edge-case) testlerinin tamamı tarafımca manuel olarak yazılmış ve doğrulanmıştır.

💻 Kurulum ve Çalıştırma
Projeyi derlemek ve simülasyonu başlatmak için terminalinizde şu komutları sırasıyla çalıştırmanız yeterlidir:

Derleme Komutu:
gcc main.c rfc9213_parser.c priority_queue.c -o api_gateway

Çalıştırma Komutu:
./api_gateway

👨‍💻 Geliştirici
Yağız Çınar Özbakır
Öğrenci Numarası: 1250505057
