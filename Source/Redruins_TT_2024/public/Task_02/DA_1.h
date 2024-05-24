// RedRuins Softworks (c)

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DA_1.generated.h"

UENUM(BlueprintType)
enum class EDataAssetVisibility : uint8
{
	EDAV_None  = 0	UMETA(DisplayName = "Value N"),
	EDAV_True  = 1	UMETA(DisplayName = "Value True"),
	EDAV_False = 2	UMETA(DisplayName = "Value False"),
};

UCLASS()
class REDRUINS_TT_2024_API UDA_1 : public UPrimaryDataAsset
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Data") EDataAssetVisibility DataAssetVisibility;

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Data Asset Ref", EditCondition = "DataAssetVisibility == EDataAssetVisibility::EDAV_True", EditConditionHides), Category = "Data")
	UPrimaryDataAsset* DataAssetRef;
};
