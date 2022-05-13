﻿// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "SampleGameChromaBP.h" //___HACK_UE4_VERSION_4_16_OR_GREATER
#include "UE4ChromaSDKRT.h"
//#include "SampleGameChromaBP.h" //___HACK_UE4_VERSION_4_15_OR_LESS
#include "ChromaSDKPluginBPLibrary.h"
#include "SampleGameButton.h"

//USampleGameChromaBP::USampleGameChromaBP(const FPostConstructInitializeProperties& PCIP) //___HACK_UE4_VERSION_4_8_OR_LESS
//	: Super(PCIP) //___HACK_UE4_VERSION_4_8_OR_LESS
USampleGameChromaBP::USampleGameChromaBP(const FObjectInitializer& ObjectInitializer) //___HACK_UE4_VERSION_4_9_OR_GREATER
	: Super(ObjectInitializer) //___HACK_UE4_VERSION_4_9_OR_GREATER
{
}

TArray<USampleGameButton*> USampleGameChromaBP::_sSampleButtons;

int USampleGameChromaBP::min(int a, int b)
{
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int USampleGameChromaBP::max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

void USampleGameChromaBP::SampleGameSetupButtonsEffects(const TArray<UButton*>& buttons)
{
	for (int i = 0; i < buttons.Num(); ++i)
	{
		UButton* button = buttons[i];
		if (button)
		{
			USampleGameButton* dynamicButton;
			dynamicButton = NewObject<USampleGameButton>();
			dynamicButton->AddToRoot(); //avoid GC collection
			dynamicButton->Name = button->GetName();
			button->OnClicked.AddDynamic(dynamicButton, &USampleGameButton::HandleClick);
		}
	}
}

void USampleGameChromaBP::SampleGameSampleStart()
{
#if PLATFORM_WINDOWS || PLATFORM_XBOXONE
	if (!UChromaSDKPluginBPLibrary::IsInitialized())
	{
		FChromaSDKAppInfoType appInfo;
		appInfo.Title = "UE4 Chroma Sample Game Application";
		appInfo.Description = "A sample application using Razer Chroma SDK";
		appInfo.Author_Name = "Razer";
		appInfo.Author_Contact = "https://github.com/razerofficial/UE4_XDK_SampleApp";

		//appInfo.SupportedDevice = 
		//    0x01 | // Keyboards
		//    0x02 | // Mice
		//    0x04 | // Headset
		//    0x08 | // Mousepads
		//    0x10 | // Keypads
		//    0x20   // ChromaLink devices
		//    ;
		appInfo.SupportedDevice = (0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20);
		appInfo.Category = 1;

		int32 result = UChromaSDKPluginBPLibrary::ChromaSDKInitSDK(appInfo);
		switch (result)
		{
		case RZRESULT_DLL_NOT_FOUND:
			UE_LOG(LogTemp, Error, TEXT("Chroma DLL is not found!"));
			break;
		case RZRESULT_DLL_INVALID_SIGNATURE:
			UE_LOG(LogTemp, Error, TEXT("Chroma DLL has an invalid signature!"));
			break;
		case RZRESULT_SUCCESS:
			break;
		default:
			UE_LOG(LogTemp, Error, TEXT("Failed to initialize Chroma!"));
			break;
		}
	}
#endif
}

void USampleGameChromaBP::SampleGameSampleEnd()
{
#if PLATFORM_WINDOWS || PLATFORM_XBOXONE
	if (UChromaSDKPluginBPLibrary::IsInitialized())
	{
		UChromaSDKPluginBPLibrary::ChromaSDKUnInit();
	}

	while (_sSampleButtons.Num() > 0)
	{
		USampleGameButton* dynamicButton = _sSampleButtons[0];
		_sSampleButtons.RemoveAt(0);
		if (dynamicButton && dynamicButton->IsValidLowLevel())
		{
			dynamicButton->RemoveFromRoot();
			dynamicButton->ConditionalBeginDestroy();
		}
	}
#endif
}
#pragma region Autogenerated

void USampleGameChromaBP::SampleGameShowEffect1()
{
}

void USampleGameChromaBP::SampleGameShowEffect1ChromaLink()
{
}

void USampleGameChromaBP::SampleGameShowEffect1Headset()
{
}

void USampleGameChromaBP::SampleGameShowEffect1Mousepad()
{
}

void USampleGameChromaBP::SampleGameShowEffect1Mouse()
{
}

void USampleGameChromaBP::SampleGameShowEffect1Keypad()
{
}

void USampleGameChromaBP::SampleGameShowEffect2()
{
}

void USampleGameChromaBP::SampleGameShowEffect2ChromaLink()
{
}

void USampleGameChromaBP::SampleGameShowEffect2Headset()
{
}

void USampleGameChromaBP::SampleGameShowEffect2Mousepad()
{
}

void USampleGameChromaBP::SampleGameShowEffect2Mouse()
{
}

void USampleGameChromaBP::SampleGameShowEffect2Keypad()
{
}

void USampleGameChromaBP::SampleGameShowEffect3()
{
}

void USampleGameChromaBP::SampleGameShowEffect3ChromaLink()
{
}

void USampleGameChromaBP::SampleGameShowEffect3Headset()
{
}

void USampleGameChromaBP::SampleGameShowEffect3Mousepad()
{
}

void USampleGameChromaBP::SampleGameShowEffect3Mouse()
{
}

void USampleGameChromaBP::SampleGameShowEffect3Keypad()
{
}

void USampleGameChromaBP::SampleGameShowEffect4()
{
}

void USampleGameChromaBP::SampleGameShowEffect4ChromaLink()
{
}

void USampleGameChromaBP::SampleGameShowEffect4Headset()
{
}

void USampleGameChromaBP::SampleGameShowEffect4Mousepad()
{
}

void USampleGameChromaBP::SampleGameShowEffect4Mouse()
{
}

void USampleGameChromaBP::SampleGameShowEffect4Keypad()
{
}

void USampleGameChromaBP::SampleGameShowEffect5()
{
}

void USampleGameChromaBP::SampleGameShowEffect5ChromaLink()
{
}

void USampleGameChromaBP::SampleGameShowEffect5Headset()
{
}

void USampleGameChromaBP::SampleGameShowEffect5Mousepad()
{
}

void USampleGameChromaBP::SampleGameShowEffect5Mouse()
{
}

void USampleGameChromaBP::SampleGameShowEffect5Keypad()
{
}

void USampleGameChromaBP::SampleGameShowEffect6()
{
}

void USampleGameChromaBP::SampleGameShowEffect6ChromaLink()
{
}

void USampleGameChromaBP::SampleGameShowEffect6Headset()
{
}

void USampleGameChromaBP::SampleGameShowEffect6Mousepad()
{
}

void USampleGameChromaBP::SampleGameShowEffect6Mouse()
{
}

void USampleGameChromaBP::SampleGameShowEffect6Keypad()
{
}

void USampleGameChromaBP::SampleGameShowEffect7()
{
}

void USampleGameChromaBP::SampleGameShowEffect7ChromaLink()
{
}

void USampleGameChromaBP::SampleGameShowEffect7Headset()
{
}

void USampleGameChromaBP::SampleGameShowEffect7Mousepad()
{
}

void USampleGameChromaBP::SampleGameShowEffect7Mouse()
{
}

void USampleGameChromaBP::SampleGameShowEffect7Keypad()
{
}

void USampleGameChromaBP::SampleGameShowEffect8()
{
}

void USampleGameChromaBP::SampleGameShowEffect8ChromaLink()
{
}

void USampleGameChromaBP::SampleGameShowEffect8Headset()
{
}

void USampleGameChromaBP::SampleGameShowEffect8Mousepad()
{
}

void USampleGameChromaBP::SampleGameShowEffect8Mouse()
{
}

void USampleGameChromaBP::SampleGameShowEffect8Keypad()
{
}

void USampleGameChromaBP::SampleGameShowEffect9()
{
}

void USampleGameChromaBP::SampleGameShowEffect9ChromaLink()
{
}

void USampleGameChromaBP::SampleGameShowEffect9Headset()
{
}

void USampleGameChromaBP::SampleGameShowEffect9Mousepad()
{
}

void USampleGameChromaBP::SampleGameShowEffect9Mouse()
{
}

void USampleGameChromaBP::SampleGameShowEffect9Keypad()
{
}

void USampleGameChromaBP::SampleGameShowEffect10()
{
}

void USampleGameChromaBP::SampleGameShowEffect10ChromaLink()
{
}

void USampleGameChromaBP::SampleGameShowEffect10Headset()
{
}

void USampleGameChromaBP::SampleGameShowEffect10Mousepad()
{
}

void USampleGameChromaBP::SampleGameShowEffect10Mouse()
{
}

void USampleGameChromaBP::SampleGameShowEffect10Keypad()
{
}

void USampleGameChromaBP::SampleGameShowEffect11()
{
}

void USampleGameChromaBP::SampleGameShowEffect11ChromaLink()
{
}

void USampleGameChromaBP::SampleGameShowEffect11Headset()
{
}

void USampleGameChromaBP::SampleGameShowEffect11Mousepad()
{
}

void USampleGameChromaBP::SampleGameShowEffect11Mouse()
{
}

void USampleGameChromaBP::SampleGameShowEffect11Keypad()
{
}

void USampleGameChromaBP::SampleGameShowEffect12()
{
}

void USampleGameChromaBP::SampleGameShowEffect12ChromaLink()
{
}

void USampleGameChromaBP::SampleGameShowEffect12Headset()
{
}

void USampleGameChromaBP::SampleGameShowEffect12Mousepad()
{
}

void USampleGameChromaBP::SampleGameShowEffect12Mouse()
{
}

void USampleGameChromaBP::SampleGameShowEffect12Keypad()
{
}

void USampleGameChromaBP::SampleGameShowEffect13()
{
}

void USampleGameChromaBP::SampleGameShowEffect13ChromaLink()
{
}

void USampleGameChromaBP::SampleGameShowEffect13Headset()
{
}

void USampleGameChromaBP::SampleGameShowEffect13Mousepad()
{
}

void USampleGameChromaBP::SampleGameShowEffect13Mouse()
{
}

void USampleGameChromaBP::SampleGameShowEffect13Keypad()
{
}

void USampleGameChromaBP::SampleGameShowEffect14()
{
}

void USampleGameChromaBP::SampleGameShowEffect14ChromaLink()
{
}

void USampleGameChromaBP::SampleGameShowEffect14Headset()
{
}

void USampleGameChromaBP::SampleGameShowEffect14Mousepad()
{
}

void USampleGameChromaBP::SampleGameShowEffect14Mouse()
{
}

void USampleGameChromaBP::SampleGameShowEffect14Keypad()
{
}

void USampleGameChromaBP::SampleGameShowEffect15()
{
}

void USampleGameChromaBP::SampleGameShowEffect15ChromaLink()
{
}

void USampleGameChromaBP::SampleGameShowEffect15Headset()
{
}

void USampleGameChromaBP::SampleGameShowEffect15Mousepad()
{
}

void USampleGameChromaBP::SampleGameShowEffect15Mouse()
{
}

void USampleGameChromaBP::SampleGameShowEffect15Keypad()
{
}
#pragma endregion
