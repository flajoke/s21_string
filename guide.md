# Как установить libcheck:
1. обновляем софт чтобы не было никаких странностей:
- `sudo apt update`
- `sudo apt upgrade`

2. вычищаем старый "check" чтобы линкер искал новый:
- `sudo apt purge check`

3. устанавливаем все зависимости:
- `sudo apt install automake autoconf libtool pkg-config texinfo`

4. достаем исходники:
- `curl --location --output CHECK.tar.gz https://github.com/libcheck/check/releases/download/0.15.2/check-0.15.2.tar.gz`
- `tar --extract --verbose --ungzip --file CHECK.tar.gz`

5. переходим в новую, распокованную директорию:
- `cd check-0.15.2`

6. просто выполняйте по порядку (может занять много времени): 
- `autoreconf --install`
- `./configure`
> убедитесь что вывод после `./configure` выглядит вот так:
> - ==========================================
> - Summary of Check 0.15.2 options:
> - fork mode ............................ yes
> - high resolution timer replacement .... no
> - snprintf replacement ................. no
> - subunit support....................... yes
> - timeout unit tests ................... yes
> - POSIX regular expressions ............ yes
> - build docs ........................... yes
> - ==========================================
 
- `make`
- `make check`
- `make install`
- `sudo ldconfig`

# Как пользоваться моим вонючим Makefile-ом:

 Есть переменная `SRC` в ней должны лежать все исходники нужные для библиотеки **s21_sting+**;
 Просто запишите в нее свой исходник вот так: `SRC = memchr.c`
 **Готово**
 
# Как пользоваться моими вонючими тестами:
Есть массив `TTEST ** test[]`, есть название теста типа: `"MEMCHR"`;
Просто добавьте название теста в массив вот так:  `&MEMCHR,`;
Есть `TESTS_COUNT` равный количеству существующих функций  которые надо тестить,
каждый раз когда добавляете свою фунцию, увеличевайте его значение соотвественно;
У каждого из тестов есть `#if 0` с нулем по дефолту, так как некоторые функции еще не существуют
это предоберегает сборку от ругающегося компайлера, чтобы потестить фунцию, просто поменяйте `#if 0` на `if 1`
 **Готово**
