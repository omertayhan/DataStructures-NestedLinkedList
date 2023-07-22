Github Repo: https://github.com/omertayhan/DataStructures-NestedLinkedList 

Kod Yazmaya başlamadan önce yazdığım kod tasarım ve planlamasına dair Taslak 

1. Sayıları oku.
2. Sayıları boşluklarla ayırarak "numbers" adlı bir diziye ata.
3. Dizideki elemanların onlar ve birler basamağını "tensDigit" ve "onesDigit" adlı iki ayrı diziye ata.
4. "tensDigit" ve "onesDigit" dizilerini linked listlere dönüştür, onlar basamağının olduğu linked listlerin adreslerini "tensLinkedLists" adlı bir linked listte, 
birler basamağını tutan linked listlerin adreslerini ise "onesLinkedLists" adlı bir linked listte tut.
5. Program ilk çalıştığında "KonumA" ve "KonumB" için dışardan değişken alalım. "KonumA" içinde "tensLinkedLists" indislerinden birini seçelim, 
"KonumB" için de "onesLinkedLists" indislerinden birini seçelim.
6. "tensLinkedLists" listesinden "KonumA" indisini seçtiğimizde, bu indisin gösterdiği adresteki linked listi "selectedListA" adlı bir değişkende tutalım; 
aynı şekilde "onesLinkedLists" için de bunu "selectedListB" adlı bir değişkende yapalım.
7. Sadece adreslerini "selectedListA" ve "selectedListB" arasında değiştirerek, bu iki listenin son halini alalım.
8. Son şeklini almış listelerimizde ortalama hesabına geçebiliriz.
9. "onesLinkedLists" listesinin her bir indisinde bulunan adreslerden o adresteki listenin elemanlarını (eğer birinde var diğerinde yoksa 0 değeri vererek) "onesResults" adlı bir diziye ata ve toplamını bulup dizi uzunluğuna bölelim.
10. Ortalamayı bulmuş olduğumuz değeri "totalUst" adlı bir değişkene ata.
11. Her bir indis için önceki adımları tekrarlayalım.
12. Aynı şekilde "tensLinkedLists" listesi için de aynı işlemi gerçekleştirelim ve "tensResults" adlı bir diziye ata, toplamını bulup dizi uzunluğuna bölelim.
13. Ortalamayı bulmuş olduğumuz değeri "totalAlt" adlı bir değişkene ata.
14. Son olarak, "totalUst" ve "totalAlt" değişkenlerini ekrana bastıralım.
