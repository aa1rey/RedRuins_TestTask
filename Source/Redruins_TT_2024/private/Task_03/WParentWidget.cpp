// RedRuins Softworks (c)


#include "Task_03/WParentWidget.h"
#include "Components/UniformGridPanel.h"
#include "Components/UniformGridSlot.h"
#include "Kismet/KismetArrayLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Task_03/WChildWidget.h"

void UWParentWidget::NativeConstruct()
{
	Super::NativeConstruct();
	FillArray();
	Init();
}

void UWParentWidget::Init()
{
	if (ChildWidgetClass == nullptr) { UE_LOG(LogTemp, Error, TEXT("ChildWidgetClass is nullptr in object: '%s'"), *GetNameSafe(this)); return; }

	int32 L_Counter = 0;
	for (int32 Row = 0; Row < MaxRows; Row++)
	{
		for (int32 Col = 0; Col < MaxColumns; Col++)
		{
			if (!ColorsArray.IsValidIndex(L_Counter)) continue;
			if (UWChildWidget* NewWidget = CreateWidget<UWChildWidget>(UGameplayStatics::GetPlayerController(GetWorld(), 0), ChildWidgetClass))
			{
				NewWidget->Params = ColorsArray[L_Counter];
				NewWidget->GridIndex = L_Counter;

				Grid->AddChildToUniformGrid(NewWidget, Row, Col);
				NewWidget->OnLeftClicked.AddDynamic(this, &UWParentWidget::RemoveGridChildAndUpdate);
				L_Counter++;
			}
		}
	}
}

void UWParentWidget::RemoveGridChildAndUpdate(int32 Index)
{
	//GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.f, FColor::Yellow, *FString::Printf(TEXT("[%i]: %s"), Index, *GetNameSafe(Grid->GetChildAt(Index))));
	Grid->RemoveChildAt(Index);
	for (int32 i = Index; i < Grid->GetChildrenCount(); i++)
	{
		if (UWChildWidget* Child = Cast<UWChildWidget>(Grid->GetChildAt(i)))
		{
			Child->GridIndex--;
			if (UUniformGridSlot* GridSlot = UWidgetLayoutLibrary::SlotAsUniformGridSlot(Child))
			{
				int32 CurrRow = GridSlot->GetRow();
				int32 CurrCol = GridSlot->GetColumn();
				if (CurrCol != 0) GridSlot->SetColumn(CurrCol - 1);
				else if (CurrRow != 0)
				{
					GridSlot->SetRow(CurrRow - 1);
					GridSlot->SetColumn(MaxColumns - 1);
				}
				else return;
			}
		}
	}
}
