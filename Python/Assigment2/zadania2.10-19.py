#tworzymy line zawierajacy wyrazy oddzielone przez spacje, tabulacje i znak nowej lini
line = "lot samolotem \t potem jazda \n motorem"
print(line)

#dzielimy linie na osobne wyrazy i zapisujemy w liscie
word_list = line.split()
print(word_list)

# 2.10  ilosc wyrazow w line
print("\n# 2.10\n")
l = len(word_list)
print(l)

# 2.11  znaki w napisie oddzielone podloga
print("\n2.11 \n")
for word in word_list:
    word_without_underscore = word
    answer11 = ""
    for character in word_without_underscore:
        answer11 = answer11+character+"_"
    answer11 = answer11[0:len(answer11)-1]
    print(answer11+" ")


# 2.12 slowo zlozone z pierwszych liter wyrazow w line
print("\n2.12a \n")
answer12 = ""
for word in word_list:
    answer12 = answer12+word[0]
print(answer12)

# 2.12 slowo zlozone z ostatnich liter wyrazow w line
print("\n2.12b\n")
answer12b = ""
for word in word_list:
    answer12b  = answer12b+word[-1]
print(answer12b)

#------------word[-1] <-- ostatni wyraz/litera

# 2.13 laczna dlugosc wyrazow w napisie
print("\n2.13 \n")
answer13 = 0
for word in word_list:
    answer13 = answer13+len(word)
print(answer13)

# 2.14 Najwiekszy wyraz i jego dlugosc
print("\n2.14 \n")
length = 0
max = ""
for word in word_list:
    if(len(word) > length):
        length = len(word)
        max = word
print("wyraz max: "+str(max)+", max length:"+str(length))

# 2.15 napis bedacy ciagiem cyfr kolejnych liczb z listy L
print("\n2.15\n")
L = [123,5124,613,1,23,5512]
napis = ""
for liczba in L:
    napis = napis+str(liczba)
print(napis)

# 2.16 zamienic ciag znakow "GvR" na "Guido van Rossum"
print("\n2.16\n")
x = 0
while(x < len(word_list)):
    if(word_list[x] == "GvR"):
        word_list[x] = "Guido van Rossum"
    x = x+1
print(word_list)

# 2.17 posortowac line alfabetycznie i wg dlugosci
print("\n2.17\n")
#sortowanie listy alfabetycznie
print("sortowanie alfabetyczne")
answer17 = sorted(word_list)
print(answer17)

#sortowanie listy wg dlugosci
print("sortowanie wg dlugosci")
answer17 = sorted(word_list, key=len, reverse=False)
print(answer17)

# 2.18 znalezc liczbe cyfr zero w duzej liczbie calkowitej
print("\n2.18\n")
number = 250003400
as_text = str(number)
answer18 = 0
for character in as_text:
    if character == "0":
        answer18 = answer18+1
print(answer18)

# 2.19 na liscie mamy liczby 1,2,3 cyfrowe
print("\n2.19\n")
L = [123,42,23,122,2,33,12]
print(', '.join([str(x).zfill(3) for x in L]))
