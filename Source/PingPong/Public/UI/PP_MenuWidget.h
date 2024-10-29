// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PP_MenuWidget.generated.h"

class UButton;

UCLASS()
class PINGPONG_API UPP_MenuWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
    UPROPERTY(meta = (BindWidget))
    UButton* CreateLobbyButton;

    UPROPERTY(meta = (BindWidget))
    UButton* FindLobbyButton;

    UPROPERTY(meta = (BindWidget))
    UButton* ExitGameButton;

    virtual void NativeOnInitialized() override;

private:
    UFUNCTION()
    void CreateLobby();

    UFUNCTION()
    void FindLobby();

    UFUNCTION()
    void ExitGame();
};
