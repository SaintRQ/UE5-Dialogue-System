# Dialogue Tool

<img width="1479" height="750" alt="1" src="https://github.com/user-attachments/assets/1561fa4e-4fde-4ea1-a0ec-ac93c648eadb" />


> **RU:** Dialogue Tool — плагин для Unreal Engine с визуальным редактором ветвящихся диалогов, переиспользуемыми библиотеками, условиями, действиями, Rich Text и независимым от UI runtime-проигрывателем.
>
> **EN:** Dialogue Tool is an Unreal Engine plugin that provides a visual editor for branching conversations, reusable dialogue libraries, conditions, actions, Rich Text, and a UI-independent runtime player.

Текущая версия разработана и проверена на **Unreal Engine 5.6**. Стиль нод обновлен - отличается от тех, что на скринах ниже.

The current version is developed and verified with **Unreal Engine 5.6**. The Node style has been updated — it differs from the ones shown in the screenshots below.

---

---

## Documentation language

[**Русский**](#русский) · [**English**](#english)

<a id="русский"></a>
<details open>
<summary><strong>🇷🇺 Русский</strong></summary>

## Содержание

- [Возможности](#возможности)
- [Установка](#установка)
- [Быстрый старт](#быстрый-старт)
- [Настройки плагина](#настройки-плагина)
- [Типы ассетов](#типы-ассетов)
- [Узлы графа](#узлы-графа)
- [Условия](#условия)
- [Действия](#действия)
- [Библиотеки диалогов](#библиотеки-диалогов)
- [Rich Text](#rich-text)
- [Подключение игрового UI в Blueprint](#подключение-игрового-ui-в-blueprint)
- [Подключение в C++](#подключение-в-c)
- [Runtime API](#runtime-api)
- [Кеш диалога](#кеш-диалога)
- [Логика выполнения](#логика-выполнения)
- [Рекомендации](#рекомендации)
- [Решение проблем](#решение-проблем)

## Возможности

- отдельные ассеты `Dialogue Object` для полноценных диалогов;
- отдельные ассеты `Dialogue Library` для переиспользуемых фрагментов;
- локальные `Monologue Object` и `Monologue Library`, проигрываемые компонентом на Actor;
- визуальный граф с темами, ответами, ветвлениями, действиями и терминальными узлами;
- несколько точек старта с условиями;
- условия для точки старта, веток `SWITCH` и ответов игрока;
- Blueprint- и C++-классы условий и действий;
- настройка параметров экземпляра условия или действия прямо внутри узла;
- последовательное выполнение нескольких действий;
- посимвольный вывод текста;
- динамическое изменение текста — как самого топика, так и ответов;
- отдельный звук для каждой реплики и ответа через событие `OnPlaySound`;
- поддержка Rich Text во время анимации текста;
- кеш первого разговора, посещённых топиков и выбранных ответов;
- выбор: скрыть недоступный ответ или оставить его видимым, но отключённым;
- runtime-проигрыватель в виде `UGameInstanceSubsystem`;
- UI не входит в плагин: можно подключить любой UMG, Common UI, Slate или собственный интерфейс.

## Установка

1. Скопируйте папку `DialogueTool` в каталог `Plugins` вашего проекта:

   ```text
   YourProject/
   └── Plugins/
       └── DialogueTool/
           ├── DialogueTool.uplugin
           └── Source/
   ```

2. Если каталог `Plugins` отсутствует, создайте его.
3. Откройте проект. Если Unreal Engine предложит пересобрать модули, согласитесь.
4. Откройте `Edit > Plugins`, найдите **Dialogue Tool** и убедитесь, что плагин включён.
5. Перезапустите редактор после включения плагина.

Для C++-проекта должны быть установлены поддерживаемый компилятор и компоненты разработки Unreal Engine. Если классы или пункты меню не появились после копирования, закройте редактор, пересоздайте project files и соберите проект ещё раз.

## Быстрый старт

1. Откройте `Project Settings > Plugins > Dialogue Tool`.
2. Заполните `Response End Dialogue Text` и `Response Return Dialogue Text`.
3. В Content Browser нажмите `Add` или правую кнопку мыши и выберите `Dialogue Tool > Dialogue Object`.
4. Откройте созданный ассет.
5. В узле `DIALOGUE START` оставьте стандартный вход `Default`.
6. Потяните провод из выхода `Default`, отпустите его на пустом месте и выберите `Add Topic`.
7. В секции `Text` узла `TOPIC` введите реплику персонажа.
8. Нажмите синюю кнопку `Add` в секции `Response`, добавьте текст ответа и соедините его выход со следующим `TOPIC`.
9. Добавьте красной кнопкой `Add Finish` терминальный ответ.
10. Сохраните ассет.
11. В игровом UI получите `Dialogue Manager`, подпишитесь на его события и только после этого вызовите `Start Dialogue`.

Минимальная схема выглядит так:

```text
DIALOGUE START: Default
        │
        ▼
      TOPIC
      ├── Response 1 ──► TOPIC
      └── Add Finish ──► завершение диалога
```

## Настройки плагина

Настройки находятся в `Project Settings > Plugins > Dialogue Tool` и сохраняются в `DefaultGame.ini`.

| Параметр | Назначение |
|---|---|
| `Auto Continue` | Автоматическая промотка текста (без клика). |
| `Auto Continue Delay` | Задержка перед автоматическим продолжением в секундах. Доступна при включённом `Auto Continue`. |
| `Allow Manual Continue` | Разрешает ручной вызов `ContinueDialogue` при включённом `Auto Continue`. |
| `Characters Per Second` | Скорость посимвольного вывода. Значение `0` или меньше показывает текст мгновенно. |
| `Response End Dialogue Text` | Текст автоматически созданного ответа, завершающего обычный диалог. Рекомендуется задать непустое значение. |
| `Response Return Dialogue Text` | Текст терминального ответа внутри библиотеки. По умолчанию — `Return`. |
| `Response Custom Text List` | Список заготовленных ответов для ноды  `TOPIC `. Выбор через `Add Custom` кнопку в ноде.|
| `Rich Text Style Set` | Data Table со структурой `RichTextStyleRow`. Используется редактором для меню тегов; ту же таблицу следует назначить игровым `RichTextBlock`. |

Эквивалентная конфигурация:

```ini
[/Script/DialogueTool.DialogueToolSettings]
AutoContinue=false
AutoContinueDelay=1.0
AllowContinueClick=true
CharactersPerSecond=20
RichTextStyleSet=/Game/UI/DT_RichTextStyle.DT_RichTextStyle
ResponseEndDialogueText=Finish dialogue
ResponseReturnDialogueText=Return
```

Для локализуемого проекта задавайте тексты через интерфейс Project Settings, чтобы они сохранялись как `FText`.

## Типы ассетов

### Dialogue Object

Главный диалог, который можно передать в `StartDialogue`. Он может содержать любые узлы, включая `TRANSIT` для вызова библиотеки.

Создание: `Content Browser > Add > Dialogue Tool > Dialogue Object`.

### Dialogue Library

Переиспользуемый фрагмент диалога. Его нельзя запустить напрямую через `StartDialogue`: библиотека вызывается из обычного диалога узлом `TRANSIT` и после завершения возвращает управление вызывающему графу.

Создание: `Content Browser > Add > Dialogue Tool > Dialogue Library`.

В библиотеке:

- `DIALOGUE START` заменён на `LIBRARY START`;
- `FINISH DIALOGUE` заменён на `RETURN`;
- `Add Finish` заменён на `Add Return`;
- узел `TRANSIT` недоступен, поэтому библиотеки не вкладываются друг в друга.

### Monologue Object / Monologue Library

Линейные варианты без ответов игрока. `Monologue Object` запускается локальным `Monologue Component`, а `Monologue Library` вызывается через `TRANSIT`. В ноде `MONOLOGUE` выбирается индекс роли из массива `Speakers`, переданного в `StartMonologue`, и при необходимости задаётся собственная задержка перехода для каждой строки.

Создание: `Content Browser > Add > Dialogue Tool > Monologue`.

### Dialogue Condition

Blueprint-класс, унаследованный от `UDialogueCondition`. Возвращает `true` или `false` и используется в стартах, ответах и `SWITCH`.

Создание: `Content Browser > Add > Dialogue Tool > Dialogue Condition`.

Чтобы видеть конкретную переменную в панели деталей "условия" внутри редактора диалогов - редактора условий - (в одной строке) укажите для переменной тег `EditInstanceOnly` (`Instance Editable` в блюпринте).

### Dialogue Action

Blueprint-класс, унаследованный от `UDialogueAction`. Выполняет игровую логику при прохождении потока через узел `ACTIONS`.

Создание: `Content Browser > Add > Dialogue Tool > Dialogue Action`.

Чтобы видеть конкретную переменную в панели деталей "действий" внутри редактора диалогов - редактора действий - (в одной строке) укажите для переменной тег EditInstanceOnly (Instance Editable в блюпринте). 

<img width="1006" height="441" alt="2" src="https://github.com/user-attachments/assets/52d810f0-82cf-4fe1-9c3c-1c26774706cf" />


## Узлы графа

Контекстное меню открывается правой кнопкой мыши на пустом месте графа. Ещё удобнее потянуть провод из нужного выхода и выбрать новый узел: он будет подключён автоматически.

Каждый выход может иметь только одно соединение. Подключение нового узла к уже занятому выходу заменяет старое соединение.

### DIALOGUE START / LIBRARY START / MONOLOGUE START

<img width="498" height="322" alt="start" src="https://github.com/user-attachments/assets/0e199b17-6836-4c89-847b-2e458b1bfbfd" />

Обязательный и неудаляемый стартовый узел. При первом открытии создаётся запись `Default`.

**Когда полезно:** для выбора начальной ветки по состоянию мира, например отдельного приветствия при первом и повторном разговоре.

Каждая запись содержит:

- имя — подпись для организации графа;
- список условий;
- отдельный выход потока.

При запуске записи проверяются сверху вниз. Используется **первая** запись, у которой прошли все условия. Если ни одна запись не подошла, `StartDialogue` возвращает `false`. Имя записи не выбирает старт программно и не влияет на runtime-логику.

Рекомендуемый порядок:

1. самые специфичные наборы условий;
2. более общие наборы;
3. последняя запись без условий как fallback.

Кнопка `Add` создаёт ещё одну точку старта. Минимум одна запись должна оставаться в узле.

### TOPIC / MONOLOGUE

<img width="591" height="384" alt="topicк" src="https://github.com/user-attachments/assets/1bb8197e-4f2b-4c57-8950-5117e7fdf766" />

Основной узел диалога. Содержит секции `Text` и `Response`.

**Когда полезно:** для реплик NPC, последовательности фраз и вариантов ответа игрока.

В монологовом ассете узел называется `MONOLOGUE`: секции ответов у него нет, поле `Role` выбирает объект из массива `Speakers`, а кнопка времени у строки позволяет включить собственную задержку автоперехода. Он полезен для реплик над персонажами, радио, субтитров и фоновых разговоров без остановки общего `Dialogue Manager`.

`Text` — последовательность реплик. Они выводятся сверху вниз. Кнопка `ContinueDialogue`:

- во время печати мгновенно раскрывает текущую реплику;
- после полного раскрытия переходит к следующей реплике;
- после последней реплики продолжает поток или показывает ответы.

В узле всегда остаётся хотя бы одна строка текста. Пустой текст допустим и раскрывается мгновенно. Если у темы есть ответы, они появятся сразу; если ответов нет, для продолжения всё равно потребуется `ContinueDialogue`.

У каждой строки `Text` есть кнопка звука. Назначенный `USoundBase` передаётся через `OnPlaySound` при начале показа этой строки.

Если ответов нет, у `TOPIC` есть один обычный выход. Если добавить ответы, у каждого ответа появляется собственный выход, а прежнее соединение переносится на первый ответ.

Кнопки ответа:

- синяя `Add` - добавить обычный ответ;
- зеленая `Add Custom` — добавить ответ из заготовленной библиотеки. Список задаётся в `Response Custom Text List` в настройках плагина;
- красная `Add Finish` - добавить ответ, завершающий диалог;
- в библиотеке красная кнопка называется `Add Return` и возвращает управление вызывающему диалогу;
- кнопка с `?` — открыть список условий ответа;
- кнопка с глазом — выбрать поведение при невыполненных условиях;
- кнопка звука — назначить `USoundBase`, который будет передан через `OnPlaySound` при выборе ответа;
- `-` — удалить ответ.

Поведение кнопки с глазом:

- включена: недоступный ответ приходит в UI как `VisibleFailure`; его нужно показать отключённым;
- выключена: недоступный ответ не приходит в событие.

Терминальный ответ (кнопка выхода\возврата) всегда доступен, всегда располагается после обычных ответов и получает текст из настроек плагина. Его собственный текст и условия не редактируются. К его выходу можно подключить `ACTIONS`, чтобы выполнить логику перед завершением или возвратом.

### ACTIONS

<img width="1112" height="532" alt="act" src="https://github.com/user-attachments/assets/cd4eaf92-486c-4661-a498-bff230ea2e7c" />

Узел выполняет список классов `UDialogueAction` в порядке сверху вниз. Его следует ставить внутрь соединения:

**Когда полезно:** чтобы между репликами выдать предмет, изменить переменную, запустить квест или выполнить другую игровую логику.

```text
TOPIC ──► ACTIONS ──► TOPIC
```

Можно соединить несколько `ACTIONS` подряд. Все найденные действия выполняются по порядку, по одному действию на следующий игровой tick, после чего поток переходит к целевому узлу.

Параметры действия, помеченные как редактируемые для экземпляра, показываются прямо рядом с выбранным классом.

### SWITCH

<img width="1235" height="530" alt="switch" src="https://github.com/user-attachments/assets/d9c95827-beb2-4081-868c-ea02e3a26514" />

Условное ветвление. В узле всегда есть минимум две ветки.

**Когда полезно:** когда продолжение зависит от условия — выполненного квеста, репутации, предмета или другого состояния игры.

- ветки проверяются сверху вниз;
- в одной ветке все условия объединяются через логическое **AND**;
- выбирается первая ветка, у которой прошли все условия;
- ветка без условий всегда проходит и подходит для fallback;
- если ни одна ветка не прошла, runtime покажет терминальный ответ (завершение диалога).


Название ветки — только подпись в редакторе. Кнопка `?` открывает условия, `Add` добавляет ветку, `-` удаляет её. Для предсказуемого результата оставляйте безусловную ветку последней.

### RANDOM

<img width="826" height="569" alt="rand" src="https://github.com/user-attachments/assets/590617b2-10bd-47b6-9397-19d7d97138c0" />

Случайно выбирает один из выходов с равной вероятностью. В узле всегда остаётся минимум два выхода; система по возможности не повторяет результат предыдущего прохода.

**Когда полезно:** для случайной реплики, реакции или небольшого разнообразия при повторных разговорах.

### SKIP TEXT

<img width="774" height="535" alt="skip" src="https://github.com/user-attachments/assets/6880f3e0-66d9-4d55-946d-03517be4a95b" />

Сохраняет на экране текст текущего `TOPIC` и сразу показывает ответы следующего `TOPIC`, не проигрывая его текст, провайдеры и звуки. Следующий топик всё равно отмечается посещённым. Если ответов у него нет, он открывается обычным способом, чтобы поток не остановился.

Узел недоступен в монологовых ассетах.

**Когда полезно:** когда вопрос и варианты ответа должны визуально восприниматься как один экран, хотя ответы хранятся в отдельном топике.

### TRANSIT

<img width="1032" height="505" alt="transit" src="https://github.com/user-attachments/assets/ee3676d7-0273-4f25-bb9a-3a436b87bf15" />

Вызывает `Dialogue Library`. Узел доступен только в обычном `Dialogue Object`.

**Когда полезно:** для повторно используемых фрагментов — приветствия торговца, обучения, проверки репутации или общего прощания.

1. Добавьте `TRANSIT`.
2. Выберите ассет библиотеки в поле узла.
3. Подключите вход `TRANSIT` к основному потоку.
4. Подключите выход `Return` к месту, где основной диалог должен продолжиться.

Когда поток входит в `TRANSIT`, библиотека выбирает первую подходящую запись `LIBRARY START`. При достижении `RETURN` или выборе `Add Return` активируется основной диалог, затем выполняются действия на линии `Return`, и поток продолжается дальше.

Если библиотека не назначена или ни одна её точка старта не подошла, библиотека пропускается, а поток сразу идёт через `Return`.

### PROVIDER

<img width="1060" height="387" alt="provider" src="https://github.com/user-attachments/assets/3bc42cf6-4de5-4071-9a24-e07e34cda338" />

Вызывает `Dialogue Provider`. Узел подключается к тексту и ответам внутри `TOPIC`, а в монологовом ассете — к тексту `MONOLOGUE`.

Позволяет динамически изменять текст внутри как топика, так и ответа.

**Когда полезно:** для подстановки имени игрока, цены, количества предметов и других значений, известных только во время игры.

### FINISH DIALOGUE / RETURN / FINISH MONOLOGUE

<img width="970" height="531" alt="finish" src="https://github.com/user-attachments/assets/8274bf87-5268-4c5a-b13d-0e4154ef721c" />

Терминальный узел без выбора ответа:

**Когда полезно:** для автоматического завершения разговора или возврата из библиотеки после реплики, ветки либо действий.

- `FINISH DIALOGUE` завершает обычный диалог;
- `FINISH MONOLOGUE` завершает локальное проигрывание монолога;
- `RETURN` завершает библиотеку и возвращает управление в `TRANSIT`.

Используйте этот узел, когда диалог должен завершиться автоматически после темы, ветки или действий. Используйте `Add Finish` / `Add Return`, когда игрок должен явно выбрать терминальный ответ.

### REROUTE

Перенаправляет провод, не меняя runtime-логику. Его можно добавить из контекстного меню провода или двойным кликом по соединению.

**Когда полезно:** для аккуратной раскладки больших графов и уменьшения пересечений проводов.

### Комментарии и редактирование графа

- `C` — создать комментарий вокруг выбранных узлов;
- `Ctrl+C` / `Ctrl+V` — копировать и вставить выбранные узлы;
- `Delete` — удалить выбранные узлы, кроме обязательного стартового узла;
- `Ctrl+Z` / `Ctrl+Y` — Undo / Redo.

Индикатор в заголовке узла показывает, существует ли путь от стартового узла до этого узла. Это помогает находить недостижимые части графа.

## Условия (Conditions)

### Создание Blueprint-условия

1. Выберите `Content Browser > Add > Dialogue Tool > Dialogue Condition`.
2. Назовите Blueprint, например `BP_DC_HasQuest`.
3. Откройте Blueprint.
4. В `Overrides` выберите `Execute Condition`.
5. Приведите вход `Context` к ожидаемому типу и верните результат проверки.
6. Скомпилируйте и сохраните Blueprint.
7. Откройте `?` у старта, ответа или ветки `SWITCH`, нажмите `Add` и выберите созданный класс.

`Context` — объект, переданный третьим аргументом в `StartDialogue`. Если контекст не передан или перестал существовать, плагин использует `GameInstance`.

Чтобы параметр условия отображался прямо в редакторе диалога, создайте переменную в Blueprint и включите у неё `Instance Editable`.

Правила вычисления:

- все условия одного списка должны вернуть `true`;
- пустой список считается успешным;
- незаполненная строка класса пропускается и не блокирует выполнение;
- точки старта и ветки `SWITCH` используют первый успешный список;
- успешный ответ получает `VisibleSuccess`;
- неуспешный ответ с включённым глазом получает `VisibleFailure`, а с выключенным глазом не попадает в `OnUpdateResponses`.

Базовая реализация `UDialogueCondition` возвращает `true`, поэтому не забудьте переопределить `ExecuteCondition`.

### Встроенные условия памяти

Плагин содержит два готовых условия для списка conditions конкретного ответа:

- `UDC_WasResponseSelected` автоматически проверяет, выбирался ли ранее содержащий его ответ;
- `UDC_WasTopicVisited` автоматически проверяет, посещался ли содержащий ответ топик до текущего входа.

В обоих условиях `ConditionResult = false` означает «ещё не выбирался/не посещался», а `true` — «уже выбирался/посещался». Ручные ID не нужны: ответы получают скрытые стабильные ID автоматически. Подробнее см. [Кеш диалога](#кеш-диалога).

## Действия (Actions)

### Создание Blueprint-действия

1. Выберите `Content Browser > Add > Dialogue Tool > Dialogue Action`.
2. Назовите Blueprint, например `BP_DA_GiveItem`.
3. В `Overrides` выберите `Execute Action`.
4. Используйте `Context` и текущий `FDialogueCache`, чтобы сформировать итоговый `FText`.
5. Скомпилируйте и сохраните Blueprint.
6. Добавьте в граф узел `ACTIONS` и выберите созданный класс.

Для параметров действия используйте переменные `Instance Editable`: тогда разные экземпляры одного класса в графе смогут, например, выдавать разные предметы или запускать разные квесты.

Действия выполняются строго по порядку. Между действиями есть один игровой tick. Если действие вызвало `FinishDialogue`, оставшаяся очередь больше не выполняется.

## Проводник (Provider)

1. Выберите `Content Browser > Add > Dialogue Tool > Dialogue Provider`.
2. Назовите Blueprint, например `BP_DP_PlayerName`.
3. В `Overrides` выберите `Execute Provider`.
4. Приведите `Context` к нужному классу и выполните игровую логику.
5. Скомпилируйте и сохраните Blueprint.
6. Добавьте в граф узел `PROVIDER` и выберите созданный класс.

## Библиотеки диалогов

Библиотеки удобны для повторяющихся фрагментов: торгового приветствия, обучения, проверки репутации, стандартного прощания и других общих веток.

Пример:

```text
Main Dialogue
TOPIC ──► TRANSIT: DL_CommonGreeting ──Return──► TOPIC

Dialogue Library
LIBRARY START ──► TOPIC ──► RETURN
```

Особенности:

- `StartDialogue` принимает только обычный `Dialogue Object`;
- одна библиотека не может вызвать другую библиотеку;
- библиотека выбирает старт по условиям, а не по имени;
- действия до `RETURN` выполняются внутри библиотеки;
- действия после выхода `Return` узла `TRANSIT` выполняются уже после возврата в основной диалог;
- имя стартовой записи рекомендуется использовать как понятную документацию ветки.

## Rich Text

1. Создайте Data Table со структурой `RichTextStyleRow`.
2. Добавьте строки стилей, например `Important`, `CharacterName` и `Warning`.
3. Назначьте таблицу в `Project Settings > Plugins > Dialogue Tool > Rich Text Style Set`.
4. В текстовом поле `TOPIC` или ответа выделите фрагмент.
5. Нажмите правую кнопку мыши и выберите `Rich Text Tags > нужный стиль`.

Редактор обернёт выделение в тег:

```text
This is <Important>important</> text.
```

Имена строк для контекстного меню могут содержать буквы, цифры, `_`, `.` и `-`.

Для корректного отображения в игре:

- используйте `RichTextBlock`, а не обычный `TextBlock`;
- назначьте ему ту же таблицу в `Text Style Set`;
- передавайте текст из `OnUpdateText` и `OnUpdateResponses` без ручного удаления тегов.

Посимвольный вывод сохраняет открытые Rich Text-теги и корректно считает поддерживаемые escape-последовательности (`&quot;`, `&lt;`, `&gt;`, `&amp;`).

## Подключение игрового UI в Blueprint

Плагин намеренно не создаёт готовый виджет. `Dialogue Manager` сообщает состояние через события, а проект решает, как его показать.

Коротко: создайте свой `User Widget` с `RichTextBlock`, контейнером ответов и кнопкой продолжения; после создания виджета подпишите его на события менеджера, запускайте диалог через `Start Dialogue`, а клики передавайте в `Continue Dialogue` и `Select Response`.

Для монолога добавьте `Monologue Component` на нужный Actor, подпишите UI на `On Update Role`, `On Update Text`, `On Play Sound` и `On Monologue Finished`, затем вызовите `Start Monologue`. Ответы и общий `Dialogue Manager` для этого не нужны.

### 1. Получите менеджер

В Player Controller, HUD, Widget Controller или другом подходящем объекте получите `Dialogue Manager` через узел получения Game Instance Subsystem и сохраните ссылку.

### 2. Подпишитесь на события до запуска

Подпишитесь до вызова `Start Dialogue`, иначе первое обновление текста может быть пропущено.

| Событие | Что делать в UI |
|---|---|
| `On Update Text` | Передать `Text` в `RichTextBlock.SetText`. |
| `On Update Responses` | Очистить контейнер и создать кнопки ответов. |
| `On Play Sound` | Воспроизвести переданный `USoundBase` для текущей реплики или выбранного ответа. |
| `On Dialogue Finished` | Сохранить возвращённый `FDialogueCache`, скрыть UI, вернуть управление игроку и удалить подписки. |

### 3. Обработайте ответы

В `On Update Responses` выполните `For Each Loop` по массиву:

1. Для каждого полученного элемента создайте кнопку с полем `Response`.
2. Если `Visibility == VisibleFailure`, покажите кнопку, но сделайте её недоступной.
3. Если `Visibility == VisibleSuccess`, разрешите нажатие.
4. Сохраните **Array Index из полученного массива** в созданной кнопке.
5. По нажатию вызовите `Select Response` с этим индексом.

> **Важно:** ответы с проваленными условиями и выключенным глазом уже исключены менеджером. `SelectResponse` ожидает индекс именно из массива, полученного событием `OnUpdateResponses`.

### 4. Обработайте продолжение

На клик по области диалога или на кнопку ввода вызывайте `Continue Dialogue`.

- если текст печатается, он раскроется полностью;
- если менеджер ожидает продолжение, будет показана следующая строка;
- если менеджер ожидает ответ, вызов ничего не изменит.

`Is Waiting For Continue` можно использовать для показа индикатора «нажмите, чтобы продолжить».

### 5. Запустите диалог

После создания UI и подписки на события вызовите:

```text
Start Dialogue(DialogueAsset, Cache, Context)
```

- `DialogueAsset` — обычный `Dialogue Object`;
- `Cache` — ранее сохранённый `FDialogueCache` или новая пустая структура для первого разговора;
- `Context` — NPC, Player Controller, компонент или другой объект, доступный условиям и действиям;
- возвращаемое значение `false` означает, что запуск не состоялся.

### 6. Завершите или прервите диалог

`Finish Dialogue` немедленно завершает runtime-проигрывание и вызывает `On Dialogue Finished` с обновлённым кешем. Вызывайте его при принудительном закрытии интерфейса, смене уровня или отмене разговора.

## Подключение в C++

### Зависимость модуля

Добавьте runtime-модуль в `YourGame.Build.cs`:

```csharp
PrivateDependencyModuleNames.AddRange(new[]
{
    "DialogueTool"
});
```

Если типы плагина используются в публичных заголовках вашего модуля, перенесите `DialogueTool` в `PublicDependencyModuleNames`.

Не добавляйте `DialogueToolEditor` в runtime-модуль игры.

### Получение и запуск менеджера

```cpp
#include "DialogueManager.h"
#include "DialogueObject.h"
#include "Engine/GameInstance.h"

UGameInstance* gameInstance = GetGameInstance();
UDialogueManager* dialogueManager = gameInstance
    ? gameInstance->GetSubsystem<UDialogueManager>()
    : nullptr;

FDialogueCache DialogueCache; // Owning-class field stored per dialogue or NPC.

if (dialogueManager && dialogue)
{
    dialogueManager->OnUpdateText.AddUniqueDynamic(this, &ThisClass::OnDialogueTextUpdated);
    dialogueManager->OnUpdateResponses.AddUniqueDynamic(this, &ThisClass::OnDialogueResponsesUpdated);
    dialogueManager->OnDialogueFinished.AddUniqueDynamic(this, &ThisClass::OnDialogueFinished);
    dialogueManager->OnPlaySound.AddUniqueDynamic(this, &ThisClass::OnPlaySound);

    const bool started = dialogueManager->StartDialogue(dialogue, DialogueCache, this);
    if (!started)
    {
        // Hide the UI and remove event bindings.
    }
}
```

Обработчики должны быть объявлены как `UFUNCTION` с точными сигнатурами делегатов:

```cpp
#include "DialogueRoot.h"

// Updates the visible dialogue text.
UFUNCTION()
void OnDialogueTextUpdated(const FText& text);

// Rebuilds response controls while preserving source array indices.
UFUNCTION()
void OnDialogueResponsesUpdated(const TArray<FDialogueResponse>& responses);

// Stores updated dialogue memory and handles completion.
UFUNCTION()
void OnDialogueFinished(const FDialogueCache& cache);

// Plays a topic or response sound requested by the dialogue manager.
UFUNCTION()
void OnPlaySound(USoundBase* Sound);

// Shows the continue marker only while explicit input is required.
void UpdatePressMarkVisibility() const;

```

В `OnDialogueFinished` сохраните полученный кеш и передайте его в следующий `StartDialogue`. При уничтожении UI или владельца удаляйте подписки. Если разговор нужно прервать, сначала обработайте `OnDialogueFinished`, чтобы не потерять обновлённую память.

### C++-условия и действия

Создавайте наследников `UDialogueCondition` и `UDialogueAction`, затем переопределяйте:

```cpp
// Evaluates the dialogue requirement.
virtual bool ExecuteCondition_Implementation(UObject* context) const override;

// Applies the dialogue side effect.
virtual void ExecuteAction_Implementation(UObject* context) override;
```

Свойства с `UPROPERTY(EditAnywhere)` будут доступны для настройки внутри экземпляра в узле графа.

## Runtime API

`UDialogueManager` — `UGameInstanceSubsystem`, поэтому один экземпляр существует на `GameInstance`.

| Метод | Назначение |
|---|---|
| `GetFromContext(const UObject*)` | Возвращает manager, связанный с `World` переданного объекта. Доступен в C++. |
| `StartDialogue(UDialogueObject*, const FDialogueCache&, UObject*)` | Сбрасывает runtime-состояние, копирует входной кеш и запускает первый подходящий старт. Возвращает успех запуска. |
| `ContinueDialogue()` | Завершает текущую анимацию текста или переходит к следующей строке. |
| `SelectResponse(int32)` | Выбирает доступный ответ по исходному индексу события. |
| `FinishDialogue()` | Немедленно завершает активный диалог и рассылает событие завершения. |
| `GetDialogueCache()` | Возвращает текущий рабочий кеш активного диалога. |
| `IsWaitingForContinue()` | Возвращает `true`, когда runtime ожидает явный вызов `ContinueDialogue`. |

| Событие | Данные |
|---|---|
| `OnUpdateText` | Текущий видимый `FText`, включая промежуточные стадии анимации. |
| `OnUpdateResponses` | Массив показанных ответов: успешных и оставленных видимыми неуспешных. |
| `OnPlaySound` | `USoundBase*`, назначенный текущей реплике или выбранному ответу. |
| `OnDialogueFinished` | Обновлённый `FDialogueCache` после полного завершения или принудительной остановки. |

`FDialogueResponse.Visibility`:

| Значение | Поведение UI |
|---|---|
| `VisibleSuccess` | Показать и разрешить выбор. |
| `VisibleFailure` | Показать, но запретить выбор. |

Ответ с проваленными conditions и выключенным глазом не получает отдельное значение видимости: он не добавляется в массив `OnUpdateResponses`.

## Кеш диалога

`FDialogueCache` передаётся в `StartDialogue`, изменяется manager во время разговора и возвращается через `OnDialogueFinished`. Чтобы память сохранялась между разговорами, владелец диалога должен сохранить возвращённую структуру и передать её при следующем запуске.

| Поле | Назначение |
|---|---|
| `IsFirstTalk` | Изначально `true`; перед `OnDialogueFinished` переключается в `false`. |
| `TopicsMemory` | Скрытые ID топиков, которые были посещены хотя бы один раз. |
| `ResponsesMemory` | Скрытые ID обычных ответов, которые игрок выбирал хотя бы один раз. |

ID топиков и ответов создаются и мигрируются автоматически. При копировании ноды ответы получают новые ID. Терминальные `Finish/Return` responses в `ResponsesMemory` не записываются.

`UDC_WasResponseSelected` и `UDC_WasTopicVisited` автоматически используют ID того response и topic, внутри которых находятся. Они предназначены для conditions ответа и не требуют ручной настройки ссылки.

Плагин не записывает кеш в SaveGame автоматически. Если память должна переживать смену уровня или перезапуск игры, сериализуйте `FDialogueCache` в своей системе сохранений.

## Логика выполнения

1. `StartDialogue` сбрасывает предыдущее runtime-состояние и копирует переданный `FDialogueCache`.
2. Библиотеку нельзя передать в `StartDialogue`.
3. Стартовые записи проверяются сверху вниз; все условия записи должны пройти.
4. Действия стартовой линии выполняются до первого целевого узла.
5. Тексты `TOPIC` показываются по порядку.
6. При наличии ответов runtime вычисляет их видимость и ждёт `SelectResponse`.
7. При отсутствии ответов выполняются действия обычного выхода и поток продолжается автоматически.
8. `SWITCH` выбирает первую успешную ветку.
9. `TRANSIT` временно переключает активный ассет на библиотеку.
10. `RETURN` восстанавливает основной диалог и продолжает его с выхода `Return`.
11. `FINISH DIALOGUE`, терминальный ответ или `FinishDialogue()` возвращают обновлённый кеш через `OnDialogueFinished` и очищают runtime-состояние.

Если поток пришёл в отсутствующее или неподключённое продолжение, менеджер создаёт терминальный ответ автоматически. Это защищает игру от зависания на незавершённой ветке, но обычно также указывает на неподключённый узел.

Повторный вызов `StartDialogue` во время активного разговора сбрасывает прежний разговор без отдельного `OnDialogueFinished` для него. Если это событие требуется вашей логике, сначала явно вызовите `FinishDialogue`.

## Рекомендации

- Всегда оставляйте безусловный старт последним.
- Всегда оставляйте безусловную ветку `SWITCH` последней.
- Не оставляйте пустые строки классов в условиях и действиях: они разрешены, но усложняют проверку графа.
- Передавайте осмысленный `Context` и используйте одинаковый ожидаемый тип во всех условиях и действиях конкретного диалога.
- Подписывайте UI на события **до** `StartDialogue`.
- Храните индекс каждого ответа из массива `OnUpdateResponses`.
- Сохраняйте кеш из `OnDialogueFinished` и передавайте его в следующий `StartDialogue`.
- Используйте `Add Finish` для явного выбора игрока и `FINISH DIALOGUE` для автоматического завершения.
- Выносите повторяющиеся последовательности в `Dialogue Library`.
- Назначайте используемые диалоги через `UPROPERTY` или другие cook-доступные ссылки, чтобы ассеты попали в packaged build.
- Проверяйте индикаторы достижимости и каждую ветку с разными состояниями условий.

## Решение проблем

### Плагин или ассеты не видны

- Проверьте, что `DialogueTool` включён в `Edit > Plugins`.
- Перезапустите Unreal Editor.
- Пересоздайте project files и пересоберите C++-проект.
- Проверьте, что папка содержит `Plugins/DialogueTool/DialogueTool.uplugin`.

### `StartDialogue` возвращает `false`

- Передан `nullptr`.
- Передан `Dialogue Library`, а не `Dialogue Object`.
- У менеджера нет доступного `World`.
- Ни одна запись `DIALOGUE START` не прошла условия.
- Убедитесь, что fallback-старт без условий расположен последним.

### Диалог запускается, но UI не получает первый текст

События были подключены после `StartDialogue`. Сначала создайте UI и подпишитесь на делегаты, затем запускайте диалог.

### В конце появляется пустая кнопка

Заполните `Response End Dialogue Text` и `Response Return Dialogue Text` в настройках плагина.

### Условие всегда проходит

- Проверьте, что в Blueprint переопределён `Execute Condition`.
- Базовая реализация возвращает `true`.
- Пустая строка класса условия пропускается.
- Проверьте тип и содержимое `Context`.

### Ответ выбирает неправильную ветку

В UI был передан индекс, не совпадающий с позицией в полученном массиве. Передавайте в `SelectResponse` точный `Array Index` из `OnUpdateResponses`.

### Недоступный ответ всё равно виден

Кнопка с глазом включает режим `AlwaysVisible`: ответ должен быть видимым, но отключённым. При выключенном глазе ответ с проваленными conditions вообще не приходит в `OnUpdateResponses`.

### Rich Text-теги не появляются в контекстном меню

- Назначьте `Rich Text Style Set`.
- Убедитесь, что таблица использует `RichTextStyleRow`.
- Сначала выделите текст.
- Проверьте имя строки: разрешены буквы, цифры, `_`, `.` и `-`.

### Rich Text отображается как обычные символы

Используйте `RichTextBlock` и назначьте ему тот же `Text Style Set`.

### Параметры условия или действия не видны в узле

Отметьте Blueprint-переменные как `Instance Editable` или объявите C++-свойства с `UPROPERTY(EditAnywhere)`.

### В конце ветки неожиданно появляется завершение диалога

Поток не имеет корректного продолжения, либо ни одна ветка `SWITCH` не прошла. Подключите выход или добавьте последнюю безусловную ветку.

</details>

<a id="english"></a>
<details>
<summary><strong>🇬🇧 English</strong></summary>

## Contents

- [Features](#features)
- [Installation](#installation)
- [Quick Start](#quick-start)
- [Plugin Settings](#plugin-settings)
- [Asset Types](#asset-types)
- [Graph Nodes](#graph-nodes)
- [Conditions](#conditions)
- [Actions](#actions)
- [Dialogue Libraries](#dialogue-libraries)
- [Rich Text](#rich-text-1)
- [Connecting Game UI in Blueprint](#connecting-game-ui-in-blueprint)
- [C++ Integration](#c-integration)
- [Runtime API](#runtime-api-1)
- [Dialogue Cache](#dialogue-cache)
- [Execution Flow](#execution-flow)
- [Recommendations](#recommendations)
- [Troubleshooting](#troubleshooting)

## Features

- separate `Dialogue Object` assets for complete dialogues;
- separate `Dialogue Library` assets for reusable fragments;
- local `Monologue Object` and `Monologue Library` assets played by an Actor component;
- a visual graph with topics, responses, branches, actions, and terminal nodes;
- multiple conditional start points;
- conditions for start points, `SWITCH` branches, and player responses;
- Blueprint and C++ condition/action classes;
- per-instance condition/action parameters editable directly inside nodes;
- sequential execution of multiple actions;
- character-by-character text output;
- dynamic text replacement for both topics and responses;
- separate sounds for dialogue lines and responses through `OnPlaySound`;
- Rich Text support during text animation;
- first-talk, visited-topic, and selected-response memory;
- choice between hiding unavailable responses or showing them disabled;
- a runtime player implemented as a `UGameInstanceSubsystem`;
- UI is not included in the plugin: you can use any UMG, Common UI, Slate, or custom interface.

## Installation

1. Copy the `DialogueTool` folder into your project's `Plugins` directory:

   ```text
   YourProject/
   └── Plugins/
       └── DialogueTool/
           ├── DialogueTool.uplugin
           └── Source/
   ```

2. If the `Plugins` directory does not exist, create it.
3. Open the project. If Unreal Engine asks to rebuild modules, accept.
4. Open `Edit > Plugins`, find **Dialogue Tool**, and make sure the plugin is enabled.
5. Restart the editor after enabling the plugin.

For a C++ project, a supported compiler and the Unreal Engine development components must be installed. If classes or menu entries do not appear after copying the plugin, close the editor, regenerate project files, and build the project again.

## Quick Start

1. Open `Project Settings > Plugins > Dialogue Tool`.
2. Fill in `Response End Dialogue Text` and `Response Return Dialogue Text`.
3. In the Content Browser, click `Add` or right-click and choose `Dialogue Tool > Dialogue Object`.
4. Open the created asset.
5. In the `DIALOGUE START` node, keep the default `Default` entry.
6. Drag a wire from the `Default` output, release it on empty graph space, and select `Add Topic`.
7. In the `Text` section of the `TOPIC` node, enter the character's line.
8. Click the blue `Add` button in the `Response` section, add response text, and connect its output to the next `TOPIC`.
9. Use the red `Add Finish` button to add a terminal response.
10. Save the asset.
11. In your game UI, get the `Dialogue Manager`, bind to its events, and only then call `Start Dialogue`.

A minimal graph looks like this:

```text
DIALOGUE START: Default
        │
        ▼
      TOPIC
       ├── Response 1 ──► TOPIC
       └── Add Finish ──► end dialogue
```

## Plugin Settings

Settings are located at `Project Settings > Plugins > Dialogue Tool` and are saved in `DefaultGame.ini`.

| Setting | Purpose |
|---|---|
| `Auto Continue` | Automatically advances fully revealed text when no response is waiting. |
| `Auto Continue Delay` | Delay before automatic continuation in seconds. Available when `Auto Continue` is enabled. |
| `Allow Manual Continue` | Allows manual `ContinueDialogue` calls while `Auto Continue` is enabled. |
| `Characters Per Second` | Character-by-character output speed. A value of `0` or less displays text instantly. |
| `Response End Dialogue Text` | Text of the automatically created response that ends a normal dialogue. A non-empty value is recommended. |
| `Response Return Dialogue Text` | Text of the terminal response inside a library. Default: `Return`. |
| `Response Custom Text List` | Predefined response texts available through the `Add Custom` button in a `TOPIC` node. |
| `Rich Text Style Set` | Data Table using the `RichTextStyleRow` structure. The editor uses it for the tag menu; the same table should be assigned to in-game `RichTextBlock` widgets. |

Equivalent configuration:

```ini
[/Script/DialogueTool.DialogueToolSettings]
AutoContinue=false
AutoContinueDelay=1.0
AllowContinueClick=true
CharactersPerSecond=20
RichTextStyleSet=/Game/UI/DT_RichTextStyle.DT_RichTextStyle
ResponseEndDialogueText=Finish dialogue
ResponseReturnDialogueText=Return
```

For localized projects, set these texts through the Project Settings UI so they are stored as `FText`.

## Asset Types

### Dialogue Object

The main dialogue asset that can be passed to `StartDialogue`. It may contain any node type, including `TRANSIT` for calling a library.

Create via: `Content Browser > Add > Dialogue Tool > Dialogue Object`.

### Dialogue Library

A reusable dialogue fragment. It cannot be started directly with `StartDialogue`: a library is called from a normal dialogue through a `TRANSIT` node and returns control to the caller when finished.

Create via: `Content Browser > Add > Dialogue Tool > Dialogue Library`.

Inside a library:

- `DIALOGUE START` is replaced with `LIBRARY START`;
- `FINISH DIALOGUE` is replaced with `RETURN`;
- `Add Finish` is replaced with `Add Return`;
- the `TRANSIT` node is unavailable, so libraries cannot be nested inside other libraries.

### Monologue Object / Monologue Library

Linear variants without player responses. A `Monologue Object` is played locally by a `Monologue Component`, while a `Monologue Library` is called through `TRANSIT`. A `MONOLOGUE` node selects a role index from the `Speakers` array passed to `StartMonologue` and can define a per-line transition delay.

Create via: `Content Browser > Add > Dialogue Tool > Monologue`.

### Dialogue Condition

A Blueprint class derived from `UDialogueCondition`. It returns `true` or `false` and can be used by starts, responses, and `SWITCH` branches.

Create via: `Content Browser > Add > Dialogue Tool > Dialogue Condition`.

To expose a specific variable in the condition Details panel inside the dialogue editor, mark that variable as `EditInstanceOnly` (`Instance Editable` in Blueprint).

### Dialogue Action

A Blueprint class derived from `UDialogueAction`. It executes gameplay logic when flow passes through an `ACTIONS` node.

Create via: `Content Browser > Add > Dialogue Tool > Dialogue Action`.

To expose a specific variable in the action Details panel inside the dialogue editor, mark that variable as `EditInstanceOnly` (`Instance Editable` in Blueprint).

<img width="1006" height="441" alt="2" src="https://github.com/user-attachments/assets/52d810f0-82cf-4fe1-9c3c-1c26774706cf" />

## Graph Nodes

The context menu opens by right-clicking empty graph space. An even faster option is to drag a wire from the required output and choose a new node; it will be connected automatically.

Each output can have only one connection. Connecting a new node to an already occupied output replaces the previous connection.

### DIALOGUE START / LIBRARY START / MONOLOGUE START

<img width="498" height="322" alt="start" src="https://github.com/user-attachments/assets/0e199b17-6836-4c89-847b-2e458b1bfbfd" />

A required, non-removable start node. The `Default` entry is created automatically when the asset is opened for the first time.

**Useful when:** the opening branch depends on world state, such as first-time and repeat greetings.

Each entry contains:

- a name used as an editor label;
- a list of conditions;
- a separate flow output.

At startup, entries are evaluated from top to bottom. The **first** entry whose conditions all pass is used. If none match, `StartDialogue` returns `false`. The entry name does not select a start programmatically and has no effect on runtime logic.

Recommended order:

1. the most specific condition sets;
2. more general sets;
3. a final entry without conditions as a fallback.

The `Add` button creates another start point. At least one entry must remain in the node.

### TOPIC / MONOLOGUE

<img width="591" height="384" alt="topicк" src="https://github.com/user-attachments/assets/1bb8197e-4f2b-4c57-8950-5117e7fdf766" />

The main dialogue node. It contains `Text` and `Response` sections.

**Useful when:** you need NPC lines, a sequence of phrases, or player response choices.

In a monologue asset the node is named `MONOLOGUE`: it has no response section, `Role` selects an object from the `Speakers` array, and each line can enable its own automatic transition delay. It is useful for overhead speech, radio, subtitles, and ambient conversations without occupying the global `Dialogue Manager`.

`Text` is a sequence of dialogue lines shown from top to bottom. The `ContinueDialogue` function:

- while text is typing, immediately reveals the current line;
- after the current line is fully revealed, advances to the next line;
- after the final line, continues the flow or shows responses.

The node always keeps at least one text row. Empty text is allowed and is revealed instantly. If the topic has responses, they are shown immediately; if it has no responses, `ContinueDialogue` is still required to proceed.

Each `Text` row has a sound button. Its assigned `USoundBase` is sent through `OnPlaySound` when that line starts.

If there are no responses, `TOPIC` has one normal output. When responses are added, each response gets its own output and the previous connection is moved to the first response.

Response buttons:

- blue `Add` — add a normal response;
- green `Add Custom` — add a response from the predefined library configured through `Response Custom Text List` in plugin settings;
- red `Add Finish` — add a response that ends the dialogue;
- in a library, the red button is named `Add Return` and returns control to the calling dialogue;
- `?` — open the response condition list;
- eye button — choose behavior when response conditions fail;
- sound button — assign a `USoundBase` sent through `OnPlaySound` when the response is selected;
- `-` — remove the response.

Eye-button behavior:

- enabled: an unavailable response is sent to the UI as `VisibleFailure`; show it disabled;
- disabled: an unavailable response is omitted from the event.

A terminal response (the finish/return button) is always available, always placed after normal responses, and gets its text from the plugin settings. Its own text and conditions cannot be edited. You can connect `ACTIONS` to its output to execute logic before finishing or returning.

### ACTIONS

<img width="1112" height="532" alt="act" src="https://github.com/user-attachments/assets/cd4eaf92-486c-4661-a498-bff230ea2e7c" />

The node executes a list of `UDialogueAction` classes from top to bottom. It should be placed inside a connection:

**Useful when:** dialogue flow must grant an item, change a variable, start a quest, or run other gameplay logic.

```text
TOPIC ──► ACTIONS ──► TOPIC
```

Several `ACTIONS` nodes can be chained. All discovered actions are executed in order, one action on each next game tick, after which flow advances to the target node.

Action parameters marked as instance-editable are shown directly next to the selected class.

### SWITCH

<img width="1235" height="530" alt="switch" src="https://github.com/user-attachments/assets/d9c95827-beb2-4081-868c-ea02e3a26514" />

Conditional branching. The node always contains at least two branches.

**Useful when:** the next branch depends on a quest, reputation, inventory item, or another game-state condition.

- branches are evaluated from top to bottom;
- all conditions inside one branch are combined with logical **AND**;
- the first branch whose conditions all pass is selected;
- a branch with no conditions always passes and works well as a fallback;
- if no branch passes, runtime shows a terminal response that ends the dialogue.

The branch name is only an editor label. `?` opens the conditions, `Add` adds a branch, and `-` removes one. For predictable behavior, keep the unconditional branch last.

### RANDOM

<img width="826" height="569" alt="rand" src="https://github.com/user-attachments/assets/c669dbbd-4a32-4b7a-a93b-10ef3c1f0200" />

Selects one output with equal probability. At least two outputs remain available; when possible, the previous result is not selected again.

**Useful when:** you want random lines, reactions, or some variety in repeated conversations.

### SKIP TEXT

<img width="774" height="535" alt="skip" src="https://github.com/user-attachments/assets/9ea7b542-7268-4bd8-9a98-e53df355d595" />

Keeps the current `TOPIC` text visible and immediately shows the next `TOPIC` responses without playing that topic's text, providers, or sounds. The skipped topic is still marked as visited. If it has no responses, it opens normally so flow cannot get stuck.

This node is unavailable in monologue assets.

**Useful when:** a question and its choices should look like one screen even though the choices are stored in a separate topic.

### TRANSIT

<img width="1032" height="505" alt="transit" src="https://github.com/user-attachments/assets/ee3676d7-0273-4f25-bb9a-3a436b87bf15" />

Calls a `Dialogue Library`. This node is available only in a normal `Dialogue Object`.

**Useful when:** you need reusable fragments such as merchant greetings, tutorials, reputation checks, or standard farewells.

1. Add `TRANSIT`.
2. Select the library asset in the node field.
3. Connect the `TRANSIT` input to the main flow.
4. Connect the `Return` output to the place where the main dialogue should continue.

When flow enters `TRANSIT`, the library selects the first matching `LIBRARY START` entry. When `RETURN` is reached or an `Add Return` response is selected, the main dialogue becomes active again, actions on the `Return` line are executed, and flow continues.

If no library is assigned or none of its start points match, the library is skipped and flow immediately continues through `Return`.

### PROVIDER

<img width="1060" height="387" alt="provider" src="https://github.com/user-attachments/assets/3bc42cf6-4de5-4071-9a24-e07e34cda338" />

Calls a `Dialogue Provider`. Connect it to text or responses inside `TOPIC`, or to `MONOLOGUE` text in a monologue asset.

Allows text to be changed dynamically for both topics and responses.

**Useful when:** text must include a player name, price, item count, or another runtime value.

### FINISH DIALOGUE / RETURN / FINISH MONOLOGUE

<img width="970" height="531" alt="finish" src="https://github.com/user-attachments/assets/8274bf87-5268-4c5a-b13d-0e4154ef721c" />

A terminal node without a response choice:

**Useful when:** a conversation should automatically end or return from a library after a line, branch, or action sequence.

- `FINISH DIALOGUE` ends a normal dialogue;
- `FINISH MONOLOGUE` ends local monologue playback;
- `RETURN` ends a library and returns control to `TRANSIT`.

Use this node when the dialogue should end automatically after a topic, branch, or action sequence. Use `Add Finish` / `Add Return` when the player should explicitly choose a terminal response.

### REROUTE

Redirects a wire without changing runtime behavior. Add it from the wire context menu or by double-clicking a connection.

**Useful when:** you need to keep a large graph readable and reduce crossing wires.

### Comments and Graph Editing

- `C` — create a comment around selected nodes;
- `Ctrl+C` / `Ctrl+V` — copy and paste selected nodes;
- `Delete` — remove selected nodes except for the required start node;
- `Ctrl+Z` / `Ctrl+Y` — Undo / Redo.

The indicator in a node header shows whether a path from the start node to that node exists. This helps identify unreachable parts of the graph.

## Conditions

### Creating a Blueprint Condition

1. Choose `Content Browser > Add > Dialogue Tool > Dialogue Condition`.
2. Name the Blueprint, for example `BP_DC_HasQuest`.
3. Open the Blueprint.
4. In `Overrides`, select `Execute Condition`.
5. Cast the `Context` input to the expected type and return the condition result.
6. Compile and save the Blueprint.
7. Open `?` on a start, response, or `SWITCH` branch, click `Add`, and select the created class.

`Context` is the object passed as the third argument to `StartDialogue`. If no context is provided or the object is no longer valid, the plugin uses `GameInstance`.

To expose a condition parameter directly in the dialogue editor, create a Blueprint variable and enable `Instance Editable`.

Evaluation rules:

- every condition in one list must return `true`;
- an empty list is considered successful;
- an empty class row is skipped and does not block execution;
- start points and `SWITCH` branches use the first successful list;
- a successful response receives `VisibleSuccess`;
- a failed response with the eye enabled receives `VisibleFailure`; with the eye disabled, it is omitted from `OnUpdateResponses`.

The base `UDialogueCondition` implementation returns `true`, so remember to override `ExecuteCondition`.

### Built-in Memory Conditions

The plugin includes two conditions intended for a specific response's condition list:

- `UDC_WasResponseSelected` automatically checks whether its containing response was selected before;
- `UDC_WasTopicVisited` automatically checks whether the topic containing that response was visited before the current entry.

For both conditions, `ConditionResult = false` means “not selected/visited yet,” while `true` means “already selected/visited.” No manual IDs are required: responses receive hidden stable IDs automatically. See [Dialogue Cache](#dialogue-cache) for details.

## Actions

### Creating a Blueprint Action

1. Choose `Content Browser > Add > Dialogue Tool > Dialogue Action`.
2. Name the Blueprint, for example `BP_DA_GiveItem`.
3. In `Overrides`, select `Execute Action`.
4. Use `Context` and the current `FDialogueCache` to generate the resulting `FText`.
5. Compile and save the Blueprint.
6. Add an `ACTIONS` node to the graph and select the created class.

Use `Instance Editable` variables for action parameters. This allows different instances of the same class in the graph to, for example, grant different items or start different quests.

Actions execute strictly in order. There is one game tick between actions. If an action calls `FinishDialogue`, the remaining action queue is not executed.

## Provider

1. Choose `Content Browser > Add > Dialogue Tool > Dialogue Provider`.
2. Name the Blueprint, for example `BP_DP_PlayerName`.
3. In `Overrides`, select `Execute Provider`.
4. Cast `Context` to the required class and execute your gameplay logic.
5. Compile and save the Blueprint.
6. Add a `PROVIDER` node to the graph and select the created class.

## Dialogue Libraries

Libraries are useful for repeated fragments such as merchant greetings, tutorials, reputation checks, standard farewells, and other shared branches.

Example:

```text
Main Dialogue
TOPIC ──► TRANSIT: DL_CommonGreeting ──Return──► TOPIC

Dialogue Library
LIBRARY START ──► TOPIC ──► RETURN
```

Notes:

- `StartDialogue` accepts only a normal `Dialogue Object`;
- one library cannot call another library;
- a library selects its start based on conditions, not by name;
- actions before `RETURN` execute inside the library;
- actions after the `Return` output of the `TRANSIT` node execute after control returns to the main dialogue;
- use start entry names as readable documentation for branches.

## Rich Text

1. Create a Data Table using the `RichTextStyleRow` structure.
2. Add style rows such as `Important`, `CharacterName`, and `Warning`.
3. Assign the table in `Project Settings > Plugins > Dialogue Tool > Rich Text Style Set`.
4. Select a fragment inside a `TOPIC` or response text field.
5. Right-click and choose `Rich Text Tags > desired style`.

The editor wraps the selection in a tag:

```text
This is <Important>important</> text.
```

Row names used in the context menu may contain letters, digits, `_`, `.`, and `-`.

For correct in-game rendering:

- use `RichTextBlock`, not a regular `TextBlock`;
- assign the same table to its `Text Style Set`;
- pass text from `OnUpdateText` and `OnUpdateResponses` without manually stripping tags.

Character-by-character output preserves open Rich Text tags and correctly handles supported escape sequences (`&quot;`, `&lt;`, `&gt;`, `&amp;`).

## Connecting Game UI in Blueprint

The plugin intentionally does not provide a ready-made widget. `Dialogue Manager` reports state through events, while the game decides how that state should be displayed.

In short: create a `User Widget` with a `RichTextBlock`, a response container, and a continue button; bind it to manager events before starting, call `Start Dialogue`, and forward clicks to `Continue Dialogue` and `Select Response`.

For monologues, add a `Monologue Component` to the relevant Actor, bind UI to `On Update Role`, `On Update Text`, `On Play Sound`, and `On Monologue Finished`, then call `Start Monologue`. Responses and the global `Dialogue Manager` are not involved.

### 1. Get the Manager

In a Player Controller, HUD, Widget Controller, or another suitable object, get the `Dialogue Manager` through the Game Instance Subsystem getter and store the reference.

### 2. Bind Events Before Starting

Bind to events before calling `Start Dialogue`, otherwise the first text update may be missed.

| Event | What to do in UI |
|---|---|
| `On Update Text` | Pass `Text` to `RichTextBlock.SetText`. |
| `On Update Responses` | Clear the container and create response buttons. |
| `On Play Sound` | Play the supplied `USoundBase` for the current line or selected response. |
| `On Dialogue Finished` | Store the returned `FDialogueCache`, hide the UI, restore player control, and remove bindings. |

### 3. Handle Responses

Inside `On Update Responses`, run a `For Each Loop` over the array:

1. Create a button for every received element using its `Response` field.
2. If `Visibility == VisibleFailure`, show the button but disable it.
3. If `Visibility == VisibleSuccess`, allow it to be clicked.
4. Store the **Array Index from the received array** in the created button.
5. On click, call `Select Response` using that index.

> **Important:** failed responses with the eye disabled have already been omitted by the manager. `SelectResponse` expects the index from the exact array received in `OnUpdateResponses`.

### 4. Handle Continue

On a click in the dialogue area or on the relevant input button, call `Continue Dialogue`.

- if text is typing, it is revealed completely;
- if the manager is waiting for continuation, the next line is shown;
- if the manager is waiting for a response, the call does nothing.

`Is Waiting For Continue` can be used to show a "press to continue" indicator.

### 5. Start the Dialogue

After creating the UI and binding its events, call:

```text
Start Dialogue(DialogueAsset, Cache, Context)
```

- `DialogueAsset` — a normal `Dialogue Object`;
- `Cache` — a previously stored `FDialogueCache`, or a new empty structure for the first conversation;
- `Context` — an NPC, Player Controller, component, or another object available to conditions and actions;
- a return value of `false` means the dialogue failed to start.

### 6. Finish or Interrupt the Dialogue

`Finish Dialogue` immediately ends runtime playback and fires `On Dialogue Finished` with the updated cache. Call it when forcibly closing the UI, changing levels, or canceling a conversation.

## C++ Integration

### Module Dependency

Add the runtime module to `YourGame.Build.cs`:

```csharp
PrivateDependencyModuleNames.AddRange(new[]
{
    "DialogueTool"
});
```

If plugin types are used in your module's public headers, move `DialogueTool` to `PublicDependencyModuleNames`.

Do not add `DialogueToolEditor` to the game's runtime module.

### Getting and Starting the Manager

```cpp
#include "DialogueManager.h"
#include "DialogueObject.h"
#include "Engine/GameInstance.h"

UGameInstance* gameInstance = GetGameInstance();
UDialogueManager* dialogueManager = gameInstance
    ? gameInstance->GetSubsystem<UDialogueManager>()
    : nullptr;

FDialogueCache DialogueCache; // Owning-class field stored per dialogue or NPC.

if (dialogueManager && dialogue)
{
    dialogueManager->OnUpdateText.AddUniqueDynamic(this, &ThisClass::OnDialogueTextUpdated);
    dialogueManager->OnUpdateResponses.AddUniqueDynamic(this, &ThisClass::OnDialogueResponsesUpdated);
    dialogueManager->OnDialogueFinished.AddUniqueDynamic(this, &ThisClass::OnDialogueFinished);
    dialogueManager->OnPlaySound.AddUniqueDynamic(this, &ThisClass::OnPlaySound);

    const bool started = dialogueManager->StartDialogue(dialogue, DialogueCache, this);
    if (!started)
    {
        // Hide the UI and remove event bindings.
    }
}
```

Handlers must be declared as `UFUNCTION` methods with delegate-compatible signatures:

```cpp
#include "DialogueRoot.h"

// Updates the visible dialogue text.
UFUNCTION()
void OnDialogueTextUpdated(const FText& text);

// Rebuilds response controls while preserving source array indices.
UFUNCTION()
void OnDialogueResponsesUpdated(const TArray<FDialogueResponse>& responses);

// Stores updated dialogue memory and handles completion.
UFUNCTION()
void OnDialogueFinished(const FDialogueCache& cache);

// Plays a topic or response sound requested by the dialogue manager.
UFUNCTION()
void OnPlaySound(USoundBase* Sound);

// Shows the continue marker only while explicit input is required.
void UpdatePressMarkVisibility() const;
```

Store the received cache in `OnDialogueFinished` and pass it to the next `StartDialogue`. When the UI or its owner is destroyed, remove event bindings. If the conversation must be interrupted, process `OnDialogueFinished` first so the updated memory is not lost.

### C++ Conditions and Actions

Create subclasses of `UDialogueCondition` and `UDialogueAction`, then override:

```cpp
// Evaluates the dialogue requirement.
virtual bool ExecuteCondition_Implementation(UObject* context) const override;

// Applies the dialogue side effect.
virtual void ExecuteAction_Implementation(UObject* context) override;
```

Properties declared with `UPROPERTY(EditAnywhere)` are available for per-instance editing inside graph nodes.

## Runtime API

`UDialogueManager` is a `UGameInstanceSubsystem`, so one instance exists per `GameInstance`.

| Method | Purpose |
|---|---|
| `GetFromContext(const UObject*)` | Returns the manager associated with the supplied object's `World`. Available in C++. |
| `StartDialogue(UDialogueObject*, const FDialogueCache&, UObject*)` | Resets runtime state, copies the supplied cache, and starts the first matching start entry. Returns whether startup succeeded. |
| `ContinueDialogue()` | Finishes the current text animation or advances to the next line. |
| `SelectResponse(int32)` | Selects an available response using the original event-array index. |
| `FinishDialogue()` | Immediately ends the active dialogue and broadcasts the completion event. |
| `GetDialogueCache()` | Returns the working cache of the active dialogue. |
| `IsWaitingForContinue()` | Returns `true` while runtime is waiting for an explicit `ContinueDialogue` call. |

| Event | Data |
|---|---|
| `OnUpdateText` | Current visible `FText`, including intermediate animation states. |
| `OnUpdateResponses` | Responses included for display: successful responses and failed responses kept visible. |
| `OnPlaySound` | The `USoundBase*` assigned to the current line or selected response. |
| `OnDialogueFinished` | Updated `FDialogueCache` after normal completion or a forced stop. |

`FDialogueResponse.Visibility`:

| Value | UI behavior |
|---|---|
| `VisibleSuccess` | Show and allow selection. |
| `VisibleFailure` | Show but disable selection. |

A response whose conditions fail while the eye is disabled does not receive a separate visibility value; it is omitted from the `OnUpdateResponses` array.

## Dialogue Cache

`FDialogueCache` is passed to `StartDialogue`, modified by the manager during playback, and returned through `OnDialogueFinished`. To retain memory between conversations, the dialogue owner must store the returned structure and supply it to the next start.

| Field | Purpose |
|---|---|
| `IsFirstTalk` | Initially `true`; changed to `false` before `OnDialogueFinished`. |
| `TopicsMemory` | Hidden IDs of topics visited at least once. |
| `ResponsesMemory` | Hidden IDs of normal responses selected at least once. |

Topic and response IDs are generated and migrated automatically. Responses receive new IDs when a node is copied. Terminal `Finish/Return` responses are not stored in `ResponsesMemory`.

`UDC_WasResponseSelected` and `UDC_WasTopicVisited` automatically use the response and topic containing them. They are intended for response condition lists and require no manually configured reference.

The plugin does not write the cache to a SaveGame automatically. Serialize `FDialogueCache` in your own save system if the memory must survive level changes or application restarts.

## Execution Flow

1. `StartDialogue` resets previous runtime state and copies the supplied `FDialogueCache`.
2. A library cannot be passed to `StartDialogue`.
3. Start entries are evaluated from top to bottom; every condition in the entry must pass.
4. Actions on the start line execute before the first target node.
5. `TOPIC` texts are shown in order.
6. If responses exist, runtime evaluates their visibility and waits for `SelectResponse`.
7. If there are no responses, actions on the normal output execute and flow continues automatically.
8. `SWITCH` selects the first successful branch.
9. `TRANSIT` temporarily changes the active asset to a library.
10. `RETURN` restores the main dialogue and continues from the `Return` output.
11. `FINISH DIALOGUE`, a terminal response, or `FinishDialogue()` returns the updated cache through `OnDialogueFinished` and clears runtime state.

If flow reaches a missing or unconnected continuation, the manager automatically creates a terminal response. This prevents the game from getting stuck on an unfinished branch, but usually also indicates an unconnected node.

Calling `StartDialogue` again while a conversation is active resets the previous conversation without firing a separate `OnDialogueFinished` for it. If your logic requires that event, explicitly call `FinishDialogue` first.

## Recommendations

- Always keep an unconditional start entry last.
- Always keep an unconditional `SWITCH` branch last.
- Do not leave empty class rows in conditions or actions: they are allowed, but make graph validation harder.
- Pass a meaningful `Context` and use the same expected context type in all conditions and actions of a given dialogue.
- Bind UI events **before** `StartDialogue`.
- Preserve each response index from the `OnUpdateResponses` array.
- Store the cache from `OnDialogueFinished` and pass it to the next `StartDialogue`.
- Use `Add Finish` for an explicit player choice and `FINISH DIALOGUE` for automatic completion.
- Move repeated sequences into a `Dialogue Library`.
- Reference used dialogues through `UPROPERTY` or other cook-visible references so the assets are included in packaged builds.
- Check reachability indicators and test every branch with different condition states.

## Troubleshooting

### Plugin or Assets Are Not Visible

- Make sure `DialogueTool` is enabled in `Edit > Plugins`.
- Restart Unreal Editor.
- Regenerate project files and rebuild the C++ project.
- Make sure the folder contains `Plugins/DialogueTool/DialogueTool.uplugin`.

### `StartDialogue` Returns `false`

- `nullptr` was passed.
- A `Dialogue Library` was passed instead of a `Dialogue Object`.
- The manager has no valid `World`.
- No `DIALOGUE START` entry passed its conditions.
- Make sure an unconditional fallback start is placed last.

### Dialogue Starts but UI Does Not Receive the First Text

Events were bound after `StartDialogue`. Create the UI and bind delegates first, then start the dialogue.

### An Empty Button Appears at the End

Fill in `Response End Dialogue Text` and `Response Return Dialogue Text` in the plugin settings.

### A Condition Always Passes

- Make sure `Execute Condition` is overridden in Blueprint.
- The base implementation returns `true`.
- An empty condition-class row is skipped.
- Check the type and contents of `Context`.

### A Response Selects the Wrong Branch

The UI passed an index that did not match the position in the received array. Pass the exact `Array Index` from `OnUpdateResponses` to `SelectResponse`.

### An Unavailable Response Is Still Visible

The eye button enables `AlwaysVisible`: the response should remain visible but disabled. With the eye disabled, a response whose conditions fail is omitted from `OnUpdateResponses` entirely.

### Rich Text Tags Do Not Appear in the Context Menu

- Assign `Rich Text Style Set`.
- Make sure the table uses `RichTextStyleRow`.
- Select some text first.
- Check the row name: letters, digits, `_`, `.`, and `-` are allowed.

### Rich Text Is Displayed as Plain Characters

Use `RichTextBlock` and assign the same `Text Style Set` to it.

### Condition or Action Parameters Are Not Visible in the Node

Mark Blueprint variables as `Instance Editable` or declare C++ properties with `UPROPERTY(EditAnywhere)`.

### Dialogue Unexpectedly Ends at the End of a Branch

The flow has no valid continuation, or no `SWITCH` branch passed. Connect the output or add a final unconditional branch.

</details>
