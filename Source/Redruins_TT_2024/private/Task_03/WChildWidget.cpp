// RedRuins Softworks (c)


#include "Task_03/WChildWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

void UWChildWidget::NativeConstruct()
{
	Super::NativeConstruct();
	SetParams();
}

FReply UWChildWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);
	if (InMouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton)) OnLeftClicked.Broadcast(GridIndex);
	return FReply::Handled();
}

void UWChildWidget::SetParams()
{
	BackgroundImage->SetColorAndOpacity(Params.BackgroundColor);

	Image_RU->SetColorAndOpacity(Params.RU);
	Image_LU->SetColorAndOpacity(Params.LU);
	Image_RD->SetColorAndOpacity(Params.RD);
	Image_LD->SetColorAndOpacity(Params.LD);
	Image_CC->SetColorAndOpacity(Params.CC);

	Text_RU->SetText(Params.RU_Text);
	Text_LU->SetText(Params.LU_Text);
	Text_RD->SetText(Params.RD_Text);
	Text_LD->SetText(Params.LD_Text);
	Text_CC->SetText(Params.CC_Text);
}
