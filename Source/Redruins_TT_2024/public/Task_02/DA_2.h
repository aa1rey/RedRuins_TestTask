// RedRuins Softworks (c)

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DA_2.generated.h"

/**
 * 
 */
UCLASS()
class REDRUINS_TT_2024_API UDA_2 : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, Category = "Data") UPrimaryDataAsset* DataAssetRef;
};
