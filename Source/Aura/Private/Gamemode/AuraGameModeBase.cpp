// Fill out your copyright notice in the Description page of Project Settings.


#include "Gamemode/AuraGameModeBase.h"
#include "Gamemode/AuraPlayerController.h"
#include "Character/HeroBaseCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAuraGameModeBase::AAuraGameModeBase()
{
	// use our custom PlayerController class
	PlayerControllerClass = AAuraPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/BP_AuraHero"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/Blueprints/BP_AuraPlayerController"));
	if (PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}
