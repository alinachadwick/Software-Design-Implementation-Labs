#  Alina Chadwick
## CS50 Spring 2021, Lab 1

#GitHub username: alinachadwick


## A
``` bash
Alina Chadwick
GitHub username: alinachadwick

```

## B
``` bash
  ln -s /thayerfs/home/f004pky/cs50-dev/shared/COVID-19/data_tables/vaccine_data/us_data/hourly file

 #symbolic link is named 'file'

```

##C
``` bash
head -1 vaccine_data_us.csv

```
 
##D
``` bash
head -1 vaccine_data_us.csv | tr \, \\n

```

##E
``` bash
grep "New Hampshire" vaccine_data_us.csv

```

##F
```bash
grep "All" vaccine_data_us.csv | cut -d "," -f2,10

```

##G
``` bash
grep "All" vaccine_data_us.csv | cut -d "," -f2,10 | sort -nk2,2 -rt ','| head -10       ## with reference to guide on how to use sort command https://phpfog.com/linux-sort-command-examples/

```

##H
``` bash
grep "All" vaccine_data_us.csv | cut -d "," -f2,10 | sort -nk2,2 -rt ','| head -10 | tr \, \|| sed -e 's/$/\|/' -e 's/^/\|/'

```
