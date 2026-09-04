// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueTextUtilities.h"

#include "Containers/StringConv.h"

void DialogueTextUtilities::BuildRevealData(
	const FString& Text,
	TArray<int32>& Offsets,
	TArray<int32>& OpenTags)
{
	Offsets.Reset();
	OpenTags.Reset();
	int32 openTags = 0;
	for (int32 index = 0; index < Text.Len();)
	{
		if (Text[index] == TEXT('<'))
		{
			const int32 tagEnd = Text.Find(
				TEXT(">"),
				ESearchCase::CaseSensitive,
				ESearchDir::FromStart,
				index + 1);
			if (tagEnd != INDEX_NONE)
			{
				int32 tagLastCharacter = tagEnd - 1;
				while (tagLastCharacter > index && FChar::IsWhitespace(Text[tagLastCharacter]))
				{
					--tagLastCharacter;
				}

				if (index + 1 < tagEnd && Text[index + 1] == TEXT('/'))
				{
					openTags = FMath::Max(0, openTags - 1);
				}
				else if (Text[tagLastCharacter] != TEXT('/'))
				{
					++openTags;
				}

				index = tagEnd + 1;
				continue;
			}
		}

		int32 characterLength = 1;
		if (Text[index] == TEXT('&'))
		{
			static constexpr const TCHAR* escapeSequences[] = {
				TEXT("&quot;"),
				TEXT("&lt;"),
				TEXT("&gt;"),
				TEXT("&amp;")
			};
			for (const TCHAR* escapeSequence : escapeSequences)
			{
				const int32 escapeLength = FCString::Strlen(escapeSequence);
				if (Text.Mid(index, escapeLength).Equals(escapeSequence, ESearchCase::CaseSensitive))
				{
					characterLength = escapeLength;
					break;
				}
			}
		}
		else if (StringConv::IsHighSurrogate(Text[index])
			&& Text.IsValidIndex(index + 1)
			&& StringConv::IsLowSurrogate(Text[index + 1]))
		{
			characterLength = 2;
		}

		index += characterLength;
		Offsets.Add(index);
		OpenTags.Add(openTags);
	}
}
