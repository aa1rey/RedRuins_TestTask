// RedRuins Softworks (c)

#pragma once

#include "CoreMinimal.h"
#include "ChildWidgetParams.generated.h"


USTRUCT(BlueprintType)
struct FChildWidgetParams
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite) FLinearColor BackgroundColor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FLinearColor RU;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FLinearColor LU;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FLinearColor RD;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FLinearColor LD;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FLinearColor CC;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) FText RU_Text;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FText LU_Text;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FText RD_Text;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FText LD_Text;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FText CC_Text;
};