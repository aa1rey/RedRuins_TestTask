// RedRuins Softworks (c)

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ChildWidgetParams.h"
#include "WChildWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLeftClicked, int32, Index);

class UImage;
class UTextBlock;

UCLASS()
class REDRUINS_TT_2024_API UWChildWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintAssignable) FOnLeftClicked OnLeftClicked;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FChildWidgetParams Params;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 GridIndex;
protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) UImage* BackgroundImage;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) UImage* Image_CC;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) UImage* Image_LU;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) UImage* Image_RU;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) UImage* Image_LD;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) UImage* Image_RD;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) UTextBlock* Text_CC;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) UTextBlock* Text_LU;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) UTextBlock* Text_RU;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) UTextBlock* Text_LD;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) UTextBlock* Text_RD;

protected:
	virtual void NativeConstruct() override;
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	void SetParams();
};
