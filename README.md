# Dialogue Tool

<img width="1653" height="654" alt="1" src="https://github.com/user-attachments/assets/37e18ea9-a194-4226-a596-3474a8adb539" />


> **RU:** Dialogue Tool — плагин для Unreal Engine с визуальным редактором ветвящихся диалогов, переиспользуемыми библиотеками, условиями, действиями, Rich Text и независимым от UI runtime-проигрывателем.
>
> **EN:** Dialogue Tool is an Unreal Engine plugin that provides a visual editor for branching conversations, reusable dialogue libraries, conditions, actions, Rich Text, and a UI-independent runtime player.

Текущая версия разработана и проверена на **Unreal Engine 5.6**. Runtime и Editor находятся в отдельных модулях, поэтому редактор графа не попадает в packaged build.

The current version is developed and verified with **Unreal Engine 5.6**. Runtime and editor code live in separate modules, so the graph editor is not included in packaged builds.

---

# Русская документация

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
- [Логика выполнения](#логика-выполнения)
- [Рекомендации](#рекомендации)
- [Решение проблем](#решение-проблем)

## Возможности

- отдельные ассеты `Dialogue Object` для полноценных диалогов;
- отдельные ассеты `Dialogue Library` для переиспользуемых фрагментов;
- визуальный граф с темами, ответами, ветвлениями, действиями и терминальными узлами;
- несколько точек старта с условиями;
- условия для точки старта, веток `SWITCH` и ответов игрока;
- Blueprint- и C++-классы условий и действий;
- настройка параметров экземпляра условия или действия прямо внутри узла;
- последовательное выполнение нескольких действий;
- посимвольный вывод текста;
- поддержка Rich Text во время анимации текста;
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
| `Characters Per Second` | Скорость посимвольного вывода. Значение `0` или меньше показывает текст мгновенно. |
| `Response End Dialogue Text` | Текст автоматически созданного ответа, завершающего обычный диалог. Рекомендуется задать непустое значение. |
| `Response Return Dialogue Text` | Текст терминального ответа внутри библиотеки. По умолчанию — `Return`. |
| `Rich Text Style Set` | Data Table со структурой `RichTextStyleRow`. Используется редактором для меню тегов; ту же таблицу следует назначить игровым `RichTextBlock`. |

Эквивалентная конфигурация:

```ini
[/Script/DialogueTool.DialogueToolSettings]
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

### Dialogue Condition

Blueprint-класс, унаследованный от `UDialogueCondition`. Возвращает `true` или `false` и используется в стартах, ответах и `SWITCH`.

Создание: `Content Browser > Add > Dialogue Tool > Dialogue Condition`.

### Dialogue Action

Blueprint-класс, унаследованный от `UDialogueAction`. Выполняет игровую логику при прохождении потока через узел `ACTIONS`.

Создание: `Content Browser > Add > Dialogue Tool > Dialogue Action`.

## Узлы графа

Контекстное меню открывается правой кнопкой мыши на пустом месте графа. Ещё удобнее потянуть провод из нужного выхода и выбрать новый узел: он будет подключён автоматически.

Каждый выход может иметь только одно соединение. Подключение нового узла к уже занятому выходу заменяет старое соединение.

### DIALOGUE START / LIBRARY START

Обязательный и неудаляемый стартовый узел. При первом открытии создаётся запись `Default`.

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

### TOPIC

Основной узел диалога. Содержит секции `Text` и `Response`.

`Text` — последовательность реплик. Они выводятся сверху вниз. Кнопка `ContinueDialogue`:

- во время печати мгновенно раскрывает текущую реплику;
- после полного раскрытия переходит к следующей реплике;
- после последней реплики продолжает поток или показывает ответы.

В узле всегда остаётся хотя бы одна строка текста. Пустой текст допустим и раскрывается мгновенно. Если у темы есть ответы, они появятся сразу; если ответов нет, для продолжения всё равно потребуется `ContinueDialogue`.

Если ответов нет, у `TOPIC` есть один обычный выход. Если добавить ответы, у каждого ответа появляется собственный выход, а прежнее соединение переносится на первый ответ.

Кнопки ответа:

- синяя `Add` — добавить обычный ответ;
- красная `Add Finish` — добавить ответ, завершающий диалог;
- в библиотеке красная кнопка называется `Add Return` и возвращает управление вызывающему диалогу;
- кнопка с `?` — открыть список условий ответа;
- кнопка с глазом — выбрать поведение при невыполненных условиях;
- `-` — удалить ответ.

Поведение кнопки с глазом:

- включена: недоступный ответ приходит в UI как `VisibleFailure`; его нужно показать отключённым;
- выключена: недоступный ответ приходит как `Invisible`; его не нужно создавать в UI.

Терминальный ответ всегда доступен, всегда располагается после обычных ответов и получает текст из настроек плагина. Его собственный текст и условия не редактируются. К его выходу можно подключить `ACTIONS`, чтобы выполнить логику перед завершением или возвратом.

### ACTIONS

Узел выполняет список классов `UDialogueAction` в порядке сверху вниз. Его следует ставить внутрь соединения:

```text
TOPIC ──► ACTIONS ──► TOPIC
```

Можно соединить несколько `ACTIONS` подряд. Все найденные действия выполняются по порядку, по одному действию на следующий игровой tick, после чего поток переходит к целевому узлу.

Параметры действия, помеченные как редактируемые для экземпляра, показываются прямо рядом с выбранным классом.

### SWITCH

Условное ветвление. В узле всегда есть минимум две ветки.

- ветки проверяются сверху вниз;
- в одной ветке все условия объединяются через логическое **AND**;
- выбирается первая ветка, у которой прошли все условия;
- ветка без условий всегда проходит и подходит для fallback;
- если ни одна ветка не прошла, runtime покажет терминальный ответ.

Название ветки — только подпись в редакторе. Кнопка `?` открывает условия, `Add` добавляет ветку, `-` удаляет её. Для предсказуемого результата оставляйте безусловную ветку последней.

### TRANSIT

Вызывает `Dialogue Library`. Узел доступен только в обычном `Dialogue Object`.

1. Добавьте `TRANSIT`.
2. Выберите ассет библиотеки в поле узла.
3. Подключите вход `TRANSIT` к основному потоку.
4. Подключите выход `Return` к месту, где основной диалог должен продолжиться.

Когда поток входит в `TRANSIT`, библиотека выбирает первую подходящую запись `LIBRARY START`. При достижении `RETURN` или выборе `Add Return` активируется основной диалог, затем выполняются действия на линии `Return`, и поток продолжается дальше.

Если библиотека не назначена или ни одна её точка старта не подошла, библиотека пропускается, а поток сразу идёт через `Return`.

### FINISH DIALOGUE / RETURN

Терминальный узел без выбора ответа:

- `FINISH DIALOGUE` завершает обычный диалог;
- `RETURN` завершает библиотеку и возвращает управление в `TRANSIT`.

Используйте этот узел, когда диалог должен завершиться автоматически после темы, ветки или действий. Используйте `Add Finish` / `Add Return`, когда игрок должен явно выбрать терминальный ответ.

### REROUTE

Визуальная точка управления проводом. Не меняет runtime-логику.

Создать её можно через `Add Reroute` или двойным щелчком по существующему проводу.

### Комментарии и редактирование графа

- `C` — создать комментарий вокруг выбранных узлов;
- `Ctrl+C` / `Ctrl+V` — копировать и вставить выбранные узлы;
- `Delete` — удалить выбранные узлы, кроме обязательного стартового узла;
- `Ctrl+Z` / `Ctrl+Y` — Undo / Redo.

Индикатор в заголовке узла показывает, существует ли путь от стартового узла до этого узла. Это помогает находить недостижимые части графа.

## Условия

### Создание Blueprint-условия

1. Выберите `Content Browser > Add > Dialogue Tool > Dialogue Condition`.
2. Назовите Blueprint, например `BP_DC_HasQuest`.
3. Откройте Blueprint.
4. В `Overrides` выберите `Execute Condition`.
5. Приведите вход `Context` к ожидаемому типу и верните результат проверки.
6. Скомпилируйте и сохраните Blueprint.
7. Откройте `?` у старта, ответа или ветки `SWITCH`, нажмите `Add` и выберите созданный класс.

`Context` — объект, переданный вторым аргументом в `StartDialogue`. Если контекст не передан или перестал существовать, плагин использует `GameInstance`.

Чтобы параметр условия отображался прямо в редакторе диалога, создайте переменную в Blueprint и включите у неё `Instance Editable`.

Правила вычисления:

- все условия одного списка должны вернуть `true`;
- пустой список считается успешным;
- незаполненная строка класса пропускается и не блокирует выполнение;
- точки старта и ветки `SWITCH` используют первый успешный список;
- условия ответа определяют `VisibleSuccess`, `VisibleFailure` или `Invisible`.

Базовая реализация `UDialogueCondition` возвращает `true`, поэтому не забудьте переопределить `ExecuteCondition`.

## Действия

### Создание Blueprint-действия

1. Выберите `Content Browser > Add > Dialogue Tool > Dialogue Action`.
2. Назовите Blueprint, например `BP_DA_GiveItem`.
3. В `Overrides` выберите `Execute Action`.
4. Приведите `Context` к нужному классу и выполните игровую логику.
5. Скомпилируйте и сохраните Blueprint.
6. Добавьте в граф узел `ACTIONS` и выберите созданный класс.

Для параметров действия используйте переменные `Instance Editable`: тогда разные экземпляры одного класса в графе смогут, например, выдавать разные предметы или запускать разные квесты.

Действия выполняются строго по порядку. Между действиями есть один игровой tick. Если действие вызвало `FinishDialogue`, оставшаяся очередь больше не выполняется.

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

### 1. Получите менеджер

В Player Controller, HUD, Widget Controller или другом подходящем объекте получите `Dialogue Manager` через узел получения Game Instance Subsystem и сохраните ссылку.

### 2. Подпишитесь на события до запуска

Подпишитесь до вызова `Start Dialogue`, иначе первое обновление текста может быть пропущено.

| Событие | Что делать в UI |
|---|---|
| `On Update Text` | Передать `Text` в `RichTextBlock.SetText`. |
| `On Update Responses` | Очистить контейнер и создать кнопки ответов. |
| `On Dialogue Finished` | Скрыть UI, вернуть управление игроку и удалить подписки. |

### 3. Обработайте ответы

В `On Update Responses` выполните `For Each Loop` по массиву:

1. Если `Visibility == Invisible`, пропустите элемент.
2. Для остальных создайте кнопку с полем `Response`.
3. Если `Visibility == VisibleFailure`, покажите кнопку, но сделайте её недоступной.
4. Если `Visibility == VisibleSuccess`, разрешите нажатие.
5. Сохраните **исходный Array Index** в созданной кнопке.
6. По нажатию вызовите `Select Response` с этим индексом.

> **Важно:** не перенумеровывайте ответы после фильтрации `Invisible`. `SelectResponse` ожидает индекс именно из массива, полученного событием `OnUpdateResponses`.

### 4. Обработайте продолжение

На клик по области диалога или на кнопку ввода вызывайте `Continue Dialogue`.

- если текст печатается, он раскроется полностью;
- если менеджер ожидает продолжение, будет показана следующая строка;
- если менеджер ожидает ответ, вызов ничего не изменит.

`Is Waiting For Continue` можно использовать для показа индикатора «нажмите, чтобы продолжить».

### 5. Запустите диалог

После создания UI и подписки на события вызовите:

```text
Start Dialogue(DialogueAsset, Context)
```

- `DialogueAsset` — обычный `Dialogue Object`;
- `Context` — NPC, Player Controller, компонент или другой объект, доступный условиям и действиям;
- возвращаемое значение `false` означает, что запуск не состоялся.

### 6. Завершите или прервите диалог

`Finish Dialogue` немедленно очищает runtime-состояние и вызывает `On Dialogue Finished`. Вызывайте его при принудительном закрытии интерфейса, смене уровня или отмене разговора.

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

if (dialogueManager && dialogue)
{
    dialogueManager->OnUpdateText.AddUniqueDynamic(this, &ThisClass::OnDialogueTextUpdated);
    dialogueManager->OnUpdateResponses.AddUniqueDynamic(this, &ThisClass::OnDialogueResponsesUpdated);
    dialogueManager->OnDialogueFinished.AddUniqueDynamic(this, &ThisClass::OnDialogueFinished);

    const bool started = dialogueManager->StartDialogue(dialogue, this);
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

// Handles dialogue completion.
UFUNCTION()
void OnDialogueFinished();
```

При уничтожении UI или владельца удаляйте подписки. Если разговор нужно прервать, после удаления подписок вызовите `FinishDialogue` либо обработайте его событие до закрытия UI.

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
| `StartDialogue(UDialogueObject*, UObject*)` | Сбрасывает прежнее состояние и запускает первый подходящий старт. Возвращает успех запуска. |
| `ContinueDialogue()` | Завершает текущую анимацию текста или переходит к следующей строке. |
| `SelectResponse(int32)` | Выбирает доступный ответ по исходному индексу события. |
| `FinishDialogue()` | Немедленно завершает активный диалог и рассылает событие завершения. |
| `IsWaitingForContinue()` | Возвращает `true`, когда runtime ожидает явный вызов `ContinueDialogue`. |

| Событие | Данные |
|---|---|
| `OnUpdateText` | Текущий видимый `FText`, включая промежуточные стадии анимации. |
| `OnUpdateResponses` | Полный массив `FDialogueResponse`, включая скрытые и отключённые ответы. |
| `OnDialogueFinished` | Уведомление о полном завершении или принудительной остановке. |

`FDialogueResponse.Visibility`:

| Значение | Поведение UI |
|---|---|
| `VisibleSuccess` | Показать и разрешить выбор. |
| `VisibleFailure` | Показать, но запретить выбор. |
| `Invisible` | Не показывать, сохранив индексы остальных элементов. |

## Логика выполнения

1. `StartDialogue` полностью сбрасывает предыдущий разговор.
2. Библиотеку нельзя передать в `StartDialogue`.
3. Стартовые записи проверяются сверху вниз; все условия записи должны пройти.
4. Действия стартовой линии выполняются до первого целевого узла.
5. Тексты `TOPIC` показываются по порядку.
6. При наличии ответов runtime вычисляет их видимость и ждёт `SelectResponse`.
7. При отсутствии ответов выполняются действия обычного выхода и поток продолжается автоматически.
8. `SWITCH` выбирает первую успешную ветку.
9. `TRANSIT` временно переключает активный ассет на библиотеку.
10. `RETURN` восстанавливает основной диалог и продолжает его с выхода `Return`.
11. `FINISH DIALOGUE`, терминальный ответ или `FinishDialogue()` очищают состояние и вызывают `OnDialogueFinished`.

Если поток пришёл в отсутствующее или неподключённое продолжение, менеджер создаёт терминальный ответ автоматически. Это защищает игру от зависания на незавершённой ветке, но обычно также указывает на неподключённый узел.

Повторный вызов `StartDialogue` во время активного разговора сбрасывает прежний разговор без отдельного `OnDialogueFinished` для него. Если это событие требуется вашей логике, сначала явно вызовите `FinishDialogue`.

## Рекомендации

- Всегда оставляйте безусловный старт последним.
- Всегда оставляйте безусловную ветку `SWITCH` последней.
- Не оставляйте пустые строки классов в условиях и действиях: они разрешены, но усложняют проверку графа.
- Передавайте осмысленный `Context` и используйте одинаковый ожидаемый тип во всех условиях и действиях конкретного диалога.
- Подписывайте UI на события **до** `StartDialogue`.
- Храните исходный индекс каждого ответа.
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

В UI был использован индекс после фильтрации скрытых ответов. Передавайте в `SelectResponse` исходный `Array Index` из `OnUpdateResponses`.

### Недоступный ответ всё равно виден

Кнопка с глазом включает режим `AlwaysVisible`: ответ должен быть видимым, но отключённым. Выключите её, чтобы получить `Invisible`, либо обработайте `Visibility` в UI.

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

---

# English Documentation

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
- [Blueprint UI Integration](#blueprint-ui-integration)
- [C++ Integration](#c-integration)
- [Runtime API](#runtime-api-1)
- [Execution Rules](#execution-rules)
- [Best Practices](#best-practices)
- [Troubleshooting](#troubleshooting)

## Features

- `Dialogue Object` assets for complete conversations;
- `Dialogue Library` assets for reusable conversation fragments;
- a visual graph with topics, responses, branches, actions, and terminal nodes;
- multiple conditional entry points;
- conditions for entry points, `SWITCH` branches, and player responses;
- Blueprint and C++ condition/action classes;
- per-node editable condition and action parameters;
- ordered execution of multiple actions;
- typewriter-style text reveal;
- Rich Text support during animated reveal;
- unavailable responses that can be hidden or shown as disabled;
- a runtime player implemented as a `UGameInstanceSubsystem`;
- no required UI framework: use UMG, Common UI, Slate, or a custom interface.

## Installation

1. Copy the `DialogueTool` folder into your project's `Plugins` directory:

   ```text
   YourProject/
   └── Plugins/
       └── DialogueTool/
           ├── DialogueTool.uplugin
           └── Source/
   ```

2. Create the `Plugins` directory if it does not exist.
3. Open the project and accept the module rebuild prompt if Unreal Engine shows one.
4. Open `Edit > Plugins`, search for **Dialogue Tool**, and make sure it is enabled.
5. Restart the editor after enabling the plugin.

A C++ project needs a supported compiler and the Unreal Engine development components. If the asset menu or plugin classes do not appear, close the editor, regenerate project files, and build the project again.

## Quick Start

1. Open `Project Settings > Plugins > Dialogue Tool`.
2. Set `Response End Dialogue Text` and `Response Return Dialogue Text`.
3. In the Content Browser, choose `Add > Dialogue Tool > Dialogue Object`.
4. Open the new asset.
5. Keep the default `Default` entry in `DIALOGUE START`.
6. Drag from the `Default` output, release on empty graph space, and choose `Add Topic`.
7. Enter the character line in the `TOPIC` node's `Text` section.
8. Use the blue `Add` button in `Response`, enter a player response, and connect its output to another `TOPIC`.
9. Use the red `Add Finish` button to add a terminal response.
10. Save the asset.
11. In the game UI, obtain the `Dialogue Manager`, bind its events, and then call `Start Dialogue`.

Minimal flow:

```text
DIALOGUE START: Default
        │
        ▼
      TOPIC
      ├── Response 1 ──► TOPIC
      └── Add Finish ──► finish dialogue
```

## Plugin Settings

Settings are available under `Project Settings > Plugins > Dialogue Tool` and are stored in `DefaultGame.ini`.

| Setting | Purpose |
|---|---|
| `Characters Per Second` | Typewriter reveal speed. A value of `0` or less reveals text immediately. |
| `Response End Dialogue Text` | Text for the generated response that ends a regular dialogue. A non-empty value is recommended. |
| `Response Return Dialogue Text` | Text for a terminal response inside a library. The default is `Return`. |
| `Rich Text Style Set` | A Data Table using `RichTextStyleRow`. The editor uses it to build the tag menu; game `RichTextBlock` widgets should use the same table. |

Equivalent configuration:

```ini
[/Script/DialogueTool.DialogueToolSettings]
CharactersPerSecond=20
RichTextStyleSet=/Game/UI/DT_RichTextStyle.DT_RichTextStyle
ResponseEndDialogueText=Finish dialogue
ResponseReturnDialogueText=Return
```

For localized projects, set response labels through Project Settings so they are stored as `FText`.

## Asset Types

### Dialogue Object

The root conversation asset accepted by `StartDialogue`. It supports every graph node, including `TRANSIT` nodes that call a library.

Create it with `Content Browser > Add > Dialogue Tool > Dialogue Object`.

### Dialogue Library

A reusable conversation fragment. It cannot be passed directly to `StartDialogue`; a regular dialogue enters it through `TRANSIT` and resumes after the library returns.

Create it with `Content Browser > Add > Dialogue Tool > Dialogue Library`.

Inside a library:

- `DIALOGUE START` becomes `LIBRARY START`;
- `FINISH DIALOGUE` becomes `RETURN`;
- `Add Finish` becomes `Add Return`;
- `TRANSIT` is unavailable, so libraries cannot nest.

### Dialogue Condition

A Blueprint class derived from `UDialogueCondition`. It returns `true` or `false` and can be assigned to starts, responses, and `SWITCH` branches.

Create it with `Content Browser > Add > Dialogue Tool > Dialogue Condition`.

### Dialogue Action

A Blueprint class derived from `UDialogueAction`. It performs gameplay logic when flow passes through an `ACTIONS` node.

Create it with `Content Browser > Add > Dialogue Tool > Dialogue Action`.

## Graph Nodes

Right-click empty graph space to open the node menu. You can also drag from an output pin and select a node; it will be connected automatically.

Each output supports one connection. Connecting a different target to an occupied output replaces the previous link.

### DIALOGUE START / LIBRARY START

The required, non-deletable entry node. A `Default` entry is created when a new asset is opened.

Each entry has:

- a name used to organize the graph;
- a condition list;
- its own flow output.

Entries are evaluated from top to bottom. The **first** entry whose conditions all pass is selected. If no entry matches, `StartDialogue` returns `false`. The entry name is not a runtime selector and does not affect execution.

Recommended order:

1. the most specific condition sets;
2. more general condition sets;
3. an unconditional fallback entry at the bottom.

The `Add` button creates another entry. At least one entry must remain.

### TOPIC

The main conversation node. It contains `Text` and `Response` sections.

`Text` is an ordered list of lines. `ContinueDialogue` behaves as follows:

- while a line is being typed, it reveals the complete current line;
- after the line is complete, it advances to the next line;
- after the final line, it continues flow or publishes responses.

At least one text entry remains in every topic. Empty text is valid and is revealed immediately. Responses appear at once when present; without responses, `ContinueDialogue` is still required to advance.

A topic without responses has one default output. Once responses are added, every response receives its own output, and the existing default link is moved to the first response.

Response controls:

- blue `Add` — add a regular response;
- red `Add Finish` — add a response that ends the conversation;
- in a library, the red button is `Add Return` and returns to the caller;
- `?` — edit response conditions;
- eye icon — choose how a failed response is presented;
- `-` — remove the response.

Eye icon behavior:

- enabled: a failed response is sent as `VisibleFailure` and should be visible but disabled;
- disabled: a failed response is sent as `Invisible` and should not be created in the UI.

A terminal response is always available, is ordered after regular responses, and gets its text from plugin settings. Its text and conditions are not editable. Connect `ACTIONS` to its output to perform work before finishing or returning.

### ACTIONS

Executes its `UDialogueAction` classes from top to bottom. Place it inside a flow connection:

```text
TOPIC ──► ACTIONS ──► TOPIC
```

Multiple `ACTIONS` nodes can be chained. All resolved actions execute in graph order, one action per next game tick, before flow enters the destination node.

Instance-editable action properties appear next to the selected class in the node.

### SWITCH

A conditional branch node with at least two branches.

- branches are evaluated from top to bottom;
- all conditions within one branch use logical **AND**;
- the first passing branch is selected;
- a branch with no conditions always passes and is suitable as a fallback;
- if no branch passes, runtime publishes a terminal response.

Branch names are editor-only labels. Use `?` to edit conditions, `Add` to append a branch, and `-` to remove one. Keep the unconditional fallback last.

### TRANSIT

Calls a `Dialogue Library`. This node is available only in a regular `Dialogue Object`.

1. Add a `TRANSIT` node.
2. Select a library asset in the node.
3. Connect its input to the main flow.
4. Connect its `Return` output to the point where the main conversation should resume.

When flow enters `TRANSIT`, the library selects its first matching `LIBRARY START` entry. Reaching `RETURN` or selecting `Add Return` restores the main dialogue, executes actions placed on the `Return` path, and continues from its destination.

If no library is assigned or no library entry matches, the library is skipped and flow proceeds through `Return` immediately.

### FINISH DIALOGUE / RETURN

A terminal node that does not require a player response:

- `FINISH DIALOGUE` ends a regular dialogue;
- `RETURN` ends a library and resumes at the caller's `TRANSIT` node.

Use it when a topic, branch, or action chain should finish automatically. Use `Add Finish` / `Add Return` when the player must explicitly select a terminal response.

### REROUTE

A visual wire control point with no runtime effect.

Create it with `Add Reroute` or by double-clicking an existing wire.

### Comments and graph editing

- `C` — create a comment around selected nodes;
- `Ctrl+C` / `Ctrl+V` — copy and paste selected nodes;
- `Delete` — delete selected nodes except the required start node;
- `Ctrl+Z` / `Ctrl+Y` — Undo / Redo.

The status indicator in a node header shows whether a path from the start node reaches that node. Use it to find unreachable graph sections.

## Conditions

### Creating a Blueprint condition

1. Choose `Content Browser > Add > Dialogue Tool > Dialogue Condition`.
2. Name the Blueprint, for example `BP_DC_HasQuest`.
3. Open it and override `Execute Condition`.
4. Cast the `Context` input to the expected type and return the check result.
5. Compile and save the Blueprint.
6. Open `?` on a start, response, or `SWITCH` branch, click `Add`, and select the class.

`Context` is the object passed as the second argument to `StartDialogue`. If no valid context is available, the plugin supplies the `GameInstance`.

Mark Blueprint variables as `Instance Editable` to expose per-instance parameters directly in the dialogue graph.

Evaluation rules:

- every condition in a list must return `true`;
- an empty list succeeds;
- an unassigned class entry is skipped and does not fail the list;
- entries and `SWITCH` branches use the first successful list;
- response conditions produce `VisibleSuccess`, `VisibleFailure`, or `Invisible`.

The base `UDialogueCondition` implementation returns `true`, so remember to override `ExecuteCondition`.

## Actions

### Creating a Blueprint action

1. Choose `Content Browser > Add > Dialogue Tool > Dialogue Action`.
2. Name the Blueprint, for example `BP_DA_GiveItem`.
3. Override `Execute Action`.
4. Cast `Context` to the required type and perform the gameplay logic.
5. Compile and save the Blueprint.
6. Add an `ACTIONS` node to the graph and select the class.

Use `Instance Editable` Blueprint variables for per-node parameters, allowing instances of the same class to grant different items, start different quests, or play different effects.

Actions execute strictly in order, with one game tick between actions. If an action calls `FinishDialogue`, the remaining queue is not executed.

## Dialogue Libraries

Libraries are useful for repeated fragments such as shop greetings, tutorials, reputation checks, or standard farewells.

Example:

```text
Main Dialogue
TOPIC ──► TRANSIT: DL_CommonGreeting ──Return──► TOPIC

Dialogue Library
LIBRARY START ──► TOPIC ──► RETURN
```

Important rules:

- `StartDialogue` accepts only a regular `Dialogue Object`;
- a library cannot call another library;
- a library selects an entry by conditions, not by name;
- actions before `RETURN` execute inside the library;
- actions after the `TRANSIT` node's `Return` output execute after the root dialogue is restored;
- entry names should be treated as readable documentation for the graph.

## Rich Text

1. Create a Data Table using `RichTextStyleRow`.
2. Add style rows such as `Important`, `CharacterName`, and `Warning`.
3. Assign it in `Project Settings > Plugins > Dialogue Tool > Rich Text Style Set`.
4. Select text inside a `TOPIC` or response field.
5. Right-click and choose `Rich Text Tags > desired style`.

The editor wraps the selection:

```text
This is <Important>important</> text.
```

Tag menu row names may contain letters, digits, `_`, `.`, and `-`.

For correct in-game rendering:

- use `RichTextBlock`, not a regular `TextBlock`;
- assign the same Data Table to its `Text Style Set`;
- pass text from `OnUpdateText` and `OnUpdateResponses` without stripping tags.

The animated reveal preserves open Rich Text tags and counts supported escape sequences (`&quot;`, `&lt;`, `&gt;`, `&amp;`) as visible characters.

## Blueprint UI Integration

The plugin intentionally does not provide a fixed widget. `Dialogue Manager` publishes state through events, and the project decides how to render it.

### 1. Obtain the manager

In a Player Controller, HUD, Widget Controller, or another suitable object, get the `Dialogue Manager` Game Instance Subsystem and store the reference.

### 2. Bind events before starting

Bind before calling `Start Dialogue`; otherwise, the first text update can be missed.

| Event | Recommended UI handling |
|---|---|
| `On Update Text` | Pass `Text` to `RichTextBlock.SetText`. |
| `On Update Responses` | Clear the response container and create response buttons. |
| `On Dialogue Finished` | Hide the UI, restore player control, and remove bindings. |

### 3. Build responses

In `On Update Responses`, run a `For Each Loop` over the array:

1. Skip items where `Visibility == Invisible`.
2. Create a button for every other item and use its `Response` text.
3. Show but disable a `VisibleFailure` response.
4. Enable a `VisibleSuccess` response.
5. Store the original **Array Index** in the created button.
6. On click, call `Select Response` with that index.

> **Important:** do not renumber responses after filtering `Invisible` entries. `SelectResponse` expects an index from the exact array supplied by `OnUpdateResponses`.

### 4. Handle continue input

Call `Continue Dialogue` when the dialogue body is clicked or the relevant input action is triggered.

- while text is typing, it reveals the full line;
- while waiting for continue, it advances to the next line;
- while waiting for a response, it does nothing.

Use `Is Waiting For Continue` to control a “press to continue” indicator.

### 5. Start the dialogue

After creating the UI and binding events, call:

```text
Start Dialogue(DialogueAsset, Context)
```

- `DialogueAsset` must be a regular `Dialogue Object`;
- `Context` can be an NPC, Player Controller, component, or any object required by conditions and actions;
- a `false` return value means playback could not start.

### 6. Finish or cancel

`Finish Dialogue` immediately clears runtime state and broadcasts `On Dialogue Finished`. Use it for forced UI closure, level changes, or conversation cancellation.

## C++ Integration

### Module dependency

Add the runtime module to `YourGame.Build.cs`:

```csharp
PrivateDependencyModuleNames.AddRange(new[]
{
    "DialogueTool"
});
```

If plugin types appear in your module's public headers, put `DialogueTool` in `PublicDependencyModuleNames` instead.

Do not add `DialogueToolEditor` to a game runtime module.

### Obtaining and starting the manager

```cpp
#include "DialogueManager.h"
#include "DialogueObject.h"
#include "Engine/GameInstance.h"

UGameInstance* gameInstance = GetGameInstance();
UDialogueManager* dialogueManager = gameInstance
    ? gameInstance->GetSubsystem<UDialogueManager>()
    : nullptr;

if (dialogueManager && dialogue)
{
    dialogueManager->OnUpdateText.AddUniqueDynamic(this, &ThisClass::OnDialogueTextUpdated);
    dialogueManager->OnUpdateResponses.AddUniqueDynamic(this, &ThisClass::OnDialogueResponsesUpdated);
    dialogueManager->OnDialogueFinished.AddUniqueDynamic(this, &ThisClass::OnDialogueFinished);

    const bool started = dialogueManager->StartDialogue(dialogue, this);
    if (!started)
    {
        // Hide the UI and remove event bindings.
    }
}
```

Handlers must be declared as `UFUNCTION` methods with exact delegate signatures:

```cpp
#include "DialogueRoot.h"

// Updates the visible dialogue text.
UFUNCTION()
void OnDialogueTextUpdated(const FText& text);

// Rebuilds response controls while preserving source array indices.
UFUNCTION()
void OnDialogueResponsesUpdated(const TArray<FDialogueResponse>& responses);

// Handles dialogue completion.
UFUNCTION()
void OnDialogueFinished();
```

Remove event bindings when the UI or owning object is destroyed. To interrupt the conversation, call `FinishDialogue` after unbinding, or handle its completion event before closing the UI.

### C++ conditions and actions

Derive from `UDialogueCondition` or `UDialogueAction` and override:

```cpp
// Evaluates the dialogue requirement.
virtual bool ExecuteCondition_Implementation(UObject* context) const override;

// Applies the dialogue side effect.
virtual void ExecuteAction_Implementation(UObject* context) override;
```

Properties declared with `UPROPERTY(EditAnywhere)` are editable on their graph instances.

## Runtime API

`UDialogueManager` is a `UGameInstanceSubsystem`, so one instance exists per `GameInstance`.

| Method | Purpose |
|---|---|
| `StartDialogue(UDialogueObject*, UObject*)` | Resets previous state and starts the first matching entry. Returns whether playback started. |
| `ContinueDialogue()` | Completes the current text animation or advances to the next line. |
| `SelectResponse(int32)` | Selects an available response using its source event index. |
| `FinishDialogue()` | Immediately ends active playback and broadcasts completion. |
| `IsWaitingForContinue()` | Returns `true` while runtime expects an explicit `ContinueDialogue` call. |

| Event | Data |
|---|---|
| `OnUpdateText` | The currently visible `FText`, including intermediate animation states. |
| `OnUpdateResponses` | The complete `FDialogueResponse` array, including hidden and disabled responses. |
| `OnDialogueFinished` | Notification that playback fully completed or was forcibly stopped. |

`FDialogueResponse.Visibility`:

| Value | UI behavior |
|---|---|
| `VisibleSuccess` | Show and enable selection. |
| `VisibleFailure` | Show but disable selection. |
| `Invisible` | Do not show; preserve all other source indices. |

## Execution Rules

1. `StartDialogue` completely resets any previous conversation.
2. A library cannot be passed to `StartDialogue`.
3. Start entries are checked from top to bottom, and every condition in an entry must pass.
4. Actions on the selected start path run before the first destination node.
5. `TOPIC` lines are presented in order.
6. If responses exist, runtime evaluates their visibility and waits for `SelectResponse`.
7. Without responses, default-output actions run and flow continues automatically.
8. `SWITCH` selects the first successful branch.
9. `TRANSIT` temporarily changes the active asset to a library.
10. `RETURN` restores the root dialogue and continues through the transit's `Return` output.
11. `FINISH DIALOGUE`, a terminal response, or `FinishDialogue()` clears state and broadcasts `OnDialogueFinished`.

If flow reaches a missing or unconnected destination, the manager publishes a generated terminal response. This prevents playback from becoming stuck, but usually indicates an unfinished graph branch.

Calling `StartDialogue` during active playback resets the previous conversation without a separate `OnDialogueFinished` event for it. If your logic needs that event, call `FinishDialogue` explicitly before starting another dialogue.

## Best Practices

- Keep an unconditional start entry last.
- Keep an unconditional `SWITCH` branch last.
- Avoid unassigned condition/action class entries: they are valid but make graphs harder to audit.
- Pass a meaningful `Context` and use a consistent expected context type across a conversation's conditions and actions.
- Bind UI events **before** calling `StartDialogue`.
- Preserve the source index of every response.
- Use `Add Finish` for an explicit player choice and `FINISH DIALOGUE` for automatic completion.
- Move repeated flows into a `Dialogue Library`.
- Reference dialogue assets through `UPROPERTY` or another cook-visible reference so they are included in packaged builds.
- Check reachability indicators and test every branch with different condition states.

## Troubleshooting

### The plugin or asset types are missing

- Make sure `DialogueTool` is enabled under `Edit > Plugins`.
- Restart Unreal Editor.
- Regenerate project files and rebuild the C++ project.
- Verify that `Plugins/DialogueTool/DialogueTool.uplugin` exists.

### `StartDialogue` returns `false`

- The dialogue is `nullptr`.
- A `Dialogue Library` was supplied instead of a `Dialogue Object`.
- The manager has no valid `World`.
- No `DIALOGUE START` entry passed its conditions.
- Keep an unconditional fallback start at the bottom.

### Playback starts but the first text update is missing

Events were bound after `StartDialogue`. Create the UI and bind delegates first, then start playback.

### A blank button appears at the end

Set `Response End Dialogue Text` and `Response Return Dialogue Text` in plugin settings.

### A condition always succeeds

- Confirm that `Execute Condition` is overridden in the Blueprint.
- The base implementation returns `true`.
- An unassigned condition class is skipped.
- Check the type and value of `Context`.

### A response selects the wrong branch

The UI used an index produced after filtering hidden responses. Pass the original `Array Index` from `OnUpdateResponses` to `SelectResponse`.

### An unavailable response is still visible

The eye button enables `AlwaysVisible`, so the response should remain visible but disabled. Turn it off to receive `Invisible`, or handle `Visibility` correctly in the UI.

### Rich Text tags are missing from the context menu

- Assign `Rich Text Style Set`.
- Make sure the table uses `RichTextStyleRow`.
- Select some text before opening the context menu.
- Check the row name; only letters, digits, `_`, `.`, and `-` are supported.

### Rich Text markup is displayed literally

Use a `RichTextBlock` and assign the same `Text Style Set`.

### Condition or action parameters are not visible in a node

Mark Blueprint variables as `Instance Editable` or declare C++ properties with `UPROPERTY(EditAnywhere)`.

### A branch unexpectedly ends the dialogue

The flow has no valid continuation, or no `SWITCH` branch passed. Connect the output or add a final unconditional branch.
