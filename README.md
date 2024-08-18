<h1>Pong 1972 by Atari</h1>

<h3>🐠Описание🐠</h3>

Моя реализация этой игры на языке <code>C</code> <br>
В коде отсуствуют указатели, массивы, структуры, классы, а также <br>
дополнительные библиотеки, только ввод/вывод и библиотека <br> 
<code>ncurses</code> для интерактивного режима

<h3>🐡Версии:🐡</h3>

<ul>
    <li><b>pong.c</b> - Пошаговая версия игры</li>
    <li><b>pong_interactive.c</b> - Интерактивная версия</li>
</ul>

<h3>🐟Сборка:🐟</h3>

Для пошаговой версии: <br>
<code>gcc -Wall -Werror -Wextra -std=c11 pong.c -o pong.out</code> 

Для интерактивной версии: <br>
<code>gcc -Wall -Werror -Wextra -lncurses -std=c11 <br> pong_interactive.c -o pong_interactive.out</code>

<h3>🪼Запуск:🪼</h3>

Достаточно запустить в терминале собранный выше файл <br>
<code>./pong.out</code> <br>
<code>./pong_interactive.out</code> <br>