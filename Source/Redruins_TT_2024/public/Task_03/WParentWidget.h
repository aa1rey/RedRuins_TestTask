// RedRuins Softworks (c)

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ChildWidgetParams.h"
#include "WParentWidget.generated.h"

/**
 * 
 */
UCLASS()
class REDRUINS_TT_2024_API UWParentWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) class UUniformGridPanel* Grid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<FChildWidgetParams> ColorsArray;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<FLinearColor> RandomColors;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FRandomStream Stream;
	UPROPERTY(EditDefaultsOnly) TSubclassOf<class UWChildWidget> ChildWidgetClass;

	UPROPERTY(EditDefaultsOnly) int32 MaxRows = 301;
	UPROPERTY(EditDefaultsOnly) int32 MaxColumns = 15;
	
protected:
	virtual void NativeConstruct() override;
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable) void FillArray();
	void Init();
	UFUNCTION(BlueprintCallable) void RemoveGridChildAndUpdate(int32 Index);
};
