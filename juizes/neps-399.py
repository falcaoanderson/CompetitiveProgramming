def eh_vogal(letra):
    for i in "aeiou":
        if letra==i:
            return True
    return False


texto = input()
vogais = "Vogais: "
consoantes = "Consoantes: "

for letra in texto:
    if(eh_vogal(letra)):
        vogais += letra
    else:
        consoantes += letra

print(vogais)
print(consoantes)

