Network Library
===============

cette librairie utilise le multiplexer select(2) et colle sur sont fonctionnement.

Select est utiliser de facon periodique et avec plusieurs set de file descriptor.
On retrouve donc un set de lecture, ecriture et d'erreur, dans chacun de ses 'set'
on peut ajouter des file descriptor - select permettra ainsi de savoir lequel des
file descriptor est utilisable l'action utilisable etant representer par le set utiliser.

Notre librairie va mettre en place un fonctionnement simplifier d'une architecture reseau
 + l'utilisation de select est abstraite
 + Buffer de lecture et d'ecriture gerant la decomposition.
 + Connection / Deconnection simplifier
 + ajout simple de connection entrante / sortant (I/O)

General
-------

Le system fonctionne sur la base d'une liste chainee, nous partiront d'un simple:

fds	pool = NULL;
// fds est un typedef struct _fds *fds;

ce fds sera plutard passer a la fonction pool qui effectura pour nous tout le travail.

cependant il est pour l'instant vide il faut donc lui ajouter quelques I/O
pour cela deux functions sont fourni:

add_co - permanttant d'ajouter une connection par le bien d'un hostname:port
add_socket - permettant d'ecouter sur un port local.

on pourrais ainsi avoir la liste suivante:

<pre>

 +---------------+       +----------------------+
 | type - SERV	 |  -- > |   type - RDWR	|
 | Port - 4242	 |       | hostname: google.fr	|
 | queue - 5	 | < --  | port: 80		|
 +---------------+	 +----------------------+

</pre>

on peut ainsi utiliser notre fonction pool de la facon suivante:

pool(&pool);

et boucler ainsi tant qu'on le desire.
pool va tout gere pour nous:

- Pour le premier maillont de type SERV:
   - lors d'une connection distance un nouveau maillont
     de type RDWR sera ajouter a la liste

- Pour le second maillont de type RDWR:
   - lors d'une reception le buffer de lecture va prendre en
     compte les nouvelle entree
   - lors d'une ecriture par l'user - vous - le buffer
     d'ecriture sera 'vider' transferer

How To ?
--------

Ainsi nos filedescriptor sont maintenant gere correctement, les connection/deconnection
sur les differentes socket sont gere, l'ecriture et la lecture est aussi gere, il ne reste plus
qu'as traiter les information recu pour en envoyer.

Pour ce faire il suffit de traverser la liste et de traiter les maillont qui vous interrese.

De plus plusieurs fonction utile sont fournit, en effet la structure buffer n'est pas defini dans
l'header 'network.h' puisque vous n'avez pas a mettre les pied dedans.

utiliser plutot:

-- Envoie
// envoie une chaine de caractere suivi du caractere de fin de ligne
void sends(fds, char*);

// envoie le caractere de fin de ligne
void eof(fds)

// envoie une chaine de caractere sans caractere de fin de ligne
void sendneof(fds, char*);

.. d'autre fonctions avec formatage a venir.

-- Reception

// renvoie un pointeur vers une chaine allouer contenant une commande sans le
// caractere de fin de command
// renvoie NULL si il n'y as rien dans le buffer de reception ou
// si il y a quelque chose mais aucun caractere de fin de commande.
char	*getcmd(fds);

Fellow Trick
------------

As part of This commit @add comit the fds struct have been change so you are
able to access the data pointer really easily.

in fact you can use some alignement trick like this.

```C
fds test = (fds)0x42; // do allocation here.
printf("test: %p\n", (*test)); // here you access the data pointer
(*(char**)test) = strdup("lol"); // here you can assigned it.
printf("hello: [%s]\n]", *(char**)test); // finaly.
```
