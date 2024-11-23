# Движок на SFML (да-да-да)

## Описание

Движок на SFML для упрощения создания 2д игр. SFML сам по себе удобен, но здесь уже заранее будут прописаны такие вещи, как: кнопки, букавы, класс по типу Unreal-овского Actor и многое другое (смотреть планы на будущее, что там заплонировано, а также что есть)

## Для чего это нужно

Создания своей игры на этом движке, а так же данный проект служит для получения опыта работы в команди с помощью Git.

## Что уже есть?

- <**EActor**>: Для управления объектами на экране
- <**EUIController**>: Для управления UI: создания кнопок, букав и т.д. на экране. Класс достаточно гибкий в этом плане (не на момент 23.11.2024)

## Установка проекта на локаль

### 1. Клонирование репазитория

Сначало следуюет клонировать репозиторий на локальную машину. Выберите удобную для вас папку, откройте терминал и выполните следующую команду:
```
git clone https://github.com/KoIIIMaPuK/HiW-Engine.git
```

### 2. Установка зависимостей  
Для работы с этим проектом потребуется библиотека SFML:
- Скачайте SFML с официального сайта.
- Распакуйте архив в удобное для вас место.
- Настройте пути в вашей среде разработки:

1. Откройте "Проект" -> "Свойства".
2. В левой панели выберите "C/C++" -> "Общие".
3. Найдите параметр "Дополнительные каталоги включаемых файлов".
4. Добавьте туда путь к папке "include" в SFML и сохраните (ОК).  
   Пример:  
   `D:\C++ Libraries\SFML-2.6.1\include`

5. В левой панели выберите "Компоновщик" -> "Общие".
6. Найдите параметр "Дополнительные каталоги библиотек".
7. Добавьте туда путь к папке "lib" в SFML и сохраните (ОК).  
   Пример:  
   `D:\C++ Libraries\SFML-2.6.1\lib`

8. Дальше в левой панели выберите "Компоновщик" -> "Ввод".
9. Найдите параметр "Дополнительные зависимости".
10. Добавьте необходимые библиотеки SFML.  
    Пример (для работы движка всё необходимое в этом примере):
    ```
    sfml-graphics-d.lib; sfml-window-d.lib; sfml-audio-d.lib; sfml-system-d.lib;
    ```

11. После всего этого ВСЕ ".dll" файлы в SFML/bin (bin лежит там же, где и include) нужно перекинуть в проект (в данном репозитории они уже лежат, поэтому ничего из 10 пункта, в теории, делать не нужно).
