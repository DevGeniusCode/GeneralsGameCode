/*
**	Command & Conquer Generals Zero Hour(tm)
**	Copyright 2025 Electronic Arts Inc.
**
**	This program is free software: you can redistribute it and/or modify
**	it under the terms of the GNU General Public License as published by
**	the Free Software Foundation, either version 3 of the License, or
**	(at your option) any later version.
**
**	This program is distributed in the hope that it will be useful,
**	but WITHOUT ANY WARRANTY; without even the implied warranty of
**	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**	GNU General Public License for more details.
**
**	You should have received a copy of the GNU General Public License
**	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

////////////////////////////////////////////////////////////////////////////////
//																																						//
//  (c) 2001-2003 Electronic Arts Inc.																				//
//																																						//
////////////////////////////////////////////////////////////////////////////////

// FILE: W3DTabControl.cpp ///////////////////////////////////////////////////
//-----------------------------------------------------------------------------
//
//                       Westwood Studios Pacific.
//
//                       Confidential Information
//                Copyright (C) 2001 - All Rights Reserved
//
//-----------------------------------------------------------------------------
//
// Project:   RTS3
//
// File name: projects\RTS\code\gameenginedevice\Source\W3DDevice\GameClient\GUI\Gadget\W3DTabControl.cpp
//
// Created:   Graham Smallwood, November 2001
//
// Desc:      W3D methods needed to implement the TabControl UI control
//
//-----------------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////

// SYSTEM INCLUDES ////////////////////////////////////////////////////////////
#include <stdlib.h>

// USER INCLUDES //////////////////////////////////////////////////////////////
#include "GameClient/GameWindowGlobal.h"
#include "GameClient/GameWindowManager.h"
#include "GameClient/GadgetTabControl.h"
#include "W3DDevice/GameClient/W3DGameWindow.h"
#include "W3DDevice/GameClient/W3DGadget.h"
#include "W3DDevice/GameClient/W3DDisplay.h"

// DEFINES ////////////////////////////////////////////////////////////////////

// PRIVATE TYPES //////////////////////////////////////////////////////////////

// PRIVATE DATA ///////////////////////////////////////////////////////////////

// PUBLIC DATA ////////////////////////////////////////////////////////////////

// PRIVATE PROTOTYPES /////////////////////////////////////////////////////////

// PRIVATE FUNCTIONS //////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// PUBLIC FUNCTIONS ///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

// W3DGadgetRadioButtonDraw ===================================================
/** Draw tabs with standard graphics */
//=============================================================================
void W3DGadgetTabControlDraw( GameWindow *tabControl, WinInstanceData *instData )
{
	ICoord2D origin, size;

	// get window position and size
	tabControl->winGetScreenPosition( &origin.x, &origin.y );
	tabControl->winGetSize( &size.x, &size.y );

	W3DGameWinDefaultDraw(tabControl, instData);//draw the background

	if( BitIsSet( tabControl->winGetStatus(), WIN_STATUS_BORDER ) == TRUE &&
			!BitIsSet( tabControl->winGetStatus(), WIN_STATUS_SEE_THRU ) )
	{//draw border if desired
		tabControl->winDrawBorder();
	}

	TabControlData *tabData = (TabControlData *)tabControl->winGetUserData();

	Int tabX, tabY, tabWidth, tabHeight, tabDeltaX, tabDeltaY;
	tabX = origin.x + tabData->tabsLeftLimit;
	tabY = origin.y + tabData->tabsTopLimit;
	tabWidth = tabData->tabWidth;
	tabHeight = tabData->tabHeight;
	if( (tabData->tabEdge == TP_TOP_SIDE)  ||  (tabData->tabEdge == TP_BOTTOM_SIDE) )
	{
		tabDeltaX = tabWidth;
		tabDeltaY = 0;
	}
	else
	{
		tabDeltaX = 0;
		tabDeltaY = tabHeight;
	}

	Color color, border;

	if( tabData->tabCount >= 1 )//Does exist
	{
		if( tabData->subPaneDisabled[0] )
		{//Disabled
			color			= GadgetTabControlGetDisabledColorTabZero( tabControl );
			border		= GadgetTabControlGetDisabledBorderColorTabZero( tabControl );
		}
		else if( tabData->activeTab == 0 )
		{//Hilited/Active
			color			= GadgetTabControlGetHiliteColorTabZero( tabControl );
			border		= GadgetTabControlGetHiliteBorderColorTabZero( tabControl );
		}
		else
		{//Just enabled
			color			= GadgetTabControlGetEnabledColorTabZero( tabControl );
			border		= GadgetTabControlGetEnabledBorderColorTabZero( tabControl );
		}

		// box and border
		if( border != WIN_COLOR_UNDEFINED )
		{
			TheWindowManager->winOpenRect( border, WIN_DRAW_LINE_WIDTH,
																		 tabX, tabY, tabX + tabWidth, tabY + tabHeight );
		}
		if( color != WIN_COLOR_UNDEFINED )
		{
			TheWindowManager->winFillRect( color, WIN_DRAW_LINE_WIDTH,
																		 tabX + 1, tabY + 1, tabX + tabWidth - 1, tabY + tabHeight - 1 );
		}
	}

	tabX += tabDeltaX;
	tabY += tabDeltaY;

	if( tabData->tabCount >= 2 )//Does exist
	{
		if( tabData->subPaneDisabled[1] )
		{//Disabled
			color			= GadgetTabControlGetDisabledColorTabOne( tabControl );
			border		= GadgetTabControlGetDisabledBorderColorTabOne( tabControl );
		}
		else if( tabData->activeTab == 1 )
		{//Hilited/Active
			color			= GadgetTabControlGetHiliteColorTabOne( tabControl );
			border		= GadgetTabControlGetHiliteBorderColorTabOne( tabControl );
		}
		else
		{//Just enabled
			color			= GadgetTabControlGetEnabledColorTabOne( tabControl );
			border		= GadgetTabControlGetEnabledBorderColorTabOne( tabControl );
		}

		// box and border
		if( border != WIN_COLOR_UNDEFINED )
		{
			TheWindowManager->winOpenRect( border, WIN_DRAW_LINE_WIDTH,
																		 tabX, tabY, tabX + tabWidth, tabY + tabHeight );
		}
		if( color != WIN_COLOR_UNDEFINED )
		{
			TheWindowManager->winFillRect( color, WIN_DRAW_LINE_WIDTH,
																		 tabX + 1, tabY + 1, tabX + tabWidth - 1, tabY + tabHeight - 1 );
		}
	}

	tabX += tabDeltaX;
	tabY += tabDeltaY;

	if( tabData->tabCount >= 3 )//Does exist
	{
		if( tabData->subPaneDisabled[2] )
		{//Disabled
			color			= GadgetTabControlGetDisabledColorTabTwo( tabControl );
			border		= GadgetTabControlGetDisabledBorderColorTabTwo( tabControl );
		}
		else if( tabData->activeTab == 2 )
		{//Hilited/Active
			color			= GadgetTabControlGetHiliteColorTabTwo( tabControl );
			border		= GadgetTabControlGetHiliteBorderColorTabTwo( tabControl );
		}
		else
		{//Just enabled
			color			= GadgetTabControlGetEnabledColorTabTwo( tabControl );
			border		= GadgetTabControlGetEnabledBorderColorTabTwo( tabControl );
		}

		// box and border
		if( border != WIN_COLOR_UNDEFINED )
		{
			TheWindowManager->winOpenRect( border, WIN_DRAW_LINE_WIDTH,
																		 tabX, tabY, tabX + tabWidth, tabY + tabHeight );
		}
		if( color != WIN_COLOR_UNDEFINED )
		{
			TheWindowManager->winFillRect( color, WIN_DRAW_LINE_WIDTH,
																		 tabX + 1, tabY + 1, tabX + tabWidth - 1, tabY + tabHeight - 1 );
		}
	}

	tabX += tabDeltaX;
	tabY += tabDeltaY;

	if( tabData->tabCount >= 4 )//Does exist
	{
		if( tabData->subPaneDisabled[3] )
		{//Disabled
			color			= GadgetTabControlGetDisabledColorTabThree( tabControl );
			border		= GadgetTabControlGetDisabledBorderColorTabThree( tabControl );
		}
		else if( tabData->activeTab == 3 )
		{//Hilited/Active
			color			= GadgetTabControlGetHiliteColorTabThree( tabControl );
			border		= GadgetTabControlGetHiliteBorderColorTabThree( tabControl );
		}
		else
		{//Just enabled
			color			= GadgetTabControlGetEnabledColorTabThree( tabControl );
			border		= GadgetTabControlGetEnabledBorderColorTabThree( tabControl );
		}

		// box and border
		if( border != WIN_COLOR_UNDEFINED )
		{
			TheWindowManager->winOpenRect( border, WIN_DRAW_LINE_WIDTH,
																		 tabX, tabY, tabX + tabWidth, tabY + tabHeight );
		}
		if( color != WIN_COLOR_UNDEFINED )
		{
			TheWindowManager->winFillRect( color, WIN_DRAW_LINE_WIDTH,
																		 tabX + 1, tabY + 1, tabX + tabWidth - 1, tabY + tabHeight - 1 );
		}
	}

	tabX += tabDeltaX;
	tabY += tabDeltaY;

	if( tabData->tabCount >= 5 )//Does exist
	{
		if( tabData->subPaneDisabled[4] )
		{//Disabled
			color			= GadgetTabControlGetDisabledColorTabFour( tabControl );
			border		= GadgetTabControlGetDisabledBorderColorTabFour( tabControl );
		}
		else if( tabData->activeTab == 4 )
		{//Hilited/Active
			color			= GadgetTabControlGetHiliteColorTabFour( tabControl );
			border		= GadgetTabControlGetHiliteBorderColorTabFour( tabControl );
		}
		else
		{//Just enabled
			color			= GadgetTabControlGetEnabledColorTabFour( tabControl );
			border		= GadgetTabControlGetEnabledBorderColorTabFour( tabControl );
		}

		// box and border
		if( border != WIN_COLOR_UNDEFINED )
		{
			TheWindowManager->winOpenRect( border, WIN_DRAW_LINE_WIDTH,
																		 tabX, tabY, tabX + tabWidth, tabY + tabHeight );
		}
		if( color != WIN_COLOR_UNDEFINED )
		{
			TheWindowManager->winFillRect( color, WIN_DRAW_LINE_WIDTH,
																		 tabX + 1, tabY + 1, tabX + tabWidth - 1, tabY + tabHeight - 1 );
		}
	}

	tabX += tabDeltaX;
	tabY += tabDeltaY;

	if( tabData->tabCount >= 6 )//Does exist
	{
		if( tabData->subPaneDisabled[5] )
		{//Disabled
			color			= GadgetTabControlGetDisabledColorTabFive( tabControl );
			border		= GadgetTabControlGetDisabledBorderColorTabFive( tabControl );
		}
		else if( tabData->activeTab == 5 )
		{//Hilited/Active
			color			= GadgetTabControlGetHiliteColorTabFive( tabControl );
			border		= GadgetTabControlGetHiliteBorderColorTabFive( tabControl );
		}
		else
		{//Just enabled
			color			= GadgetTabControlGetEnabledColorTabFive( tabControl );
			border		= GadgetTabControlGetEnabledBorderColorTabFive( tabControl );
		}

		// box and border
		if( border != WIN_COLOR_UNDEFINED )
		{
			TheWindowManager->winOpenRect( border, WIN_DRAW_LINE_WIDTH,
																		 tabX, tabY, tabX + tabWidth, tabY + tabHeight );
		}
		if( color != WIN_COLOR_UNDEFINED )
		{
			TheWindowManager->winFillRect( color, WIN_DRAW_LINE_WIDTH,
																		 tabX + 1, tabY + 1, tabX + tabWidth - 1, tabY + tabHeight - 1 );
		}
	}

	tabX += tabDeltaX;
	tabY += tabDeltaY;

	if( tabData->tabCount >= 7 )//Doesn't exist
	{
		if( tabData->subPaneDisabled[6] )
		{//Disabled
			color			= GadgetTabControlGetDisabledColorTabSix( tabControl );
			border		= GadgetTabControlGetDisabledBorderColorTabSix( tabControl );
		}
		else if( tabData->activeTab == 6 )
		{//Hilited/Active
			color			= GadgetTabControlGetHiliteColorTabSix( tabControl );
			border		= GadgetTabControlGetHiliteBorderColorTabSix( tabControl );
		}
		else
		{//Just enabled
			color			= GadgetTabControlGetEnabledColorTabSix( tabControl );
			border		= GadgetTabControlGetEnabledBorderColorTabSix( tabControl );
		}

		// box and border
		if( border != WIN_COLOR_UNDEFINED )
		{
			TheWindowManager->winOpenRect( border, WIN_DRAW_LINE_WIDTH,
																		 tabX, tabY, tabX + tabWidth, tabY + tabHeight );
		}
		if( color != WIN_COLOR_UNDEFINED )
		{
			TheWindowManager->winFillRect( color, WIN_DRAW_LINE_WIDTH,
																		 tabX + 1, tabY + 1, tabX + tabWidth - 1, tabY + tabHeight - 1 );
		}
	}

	tabX += tabDeltaX;
	tabY += tabDeltaY;

	if( tabData->tabCount >= 8 )//Doesn't exist
	{
		if( tabData->subPaneDisabled[7] )
		{//Disabled
			color			= GadgetTabControlGetDisabledColorTabSeven( tabControl );
			border		= GadgetTabControlGetDisabledBorderColorTabSeven( tabControl );
		}
		else if( tabData->activeTab == 7 )
		{//Hilited/Active
			color			= GadgetTabControlGetHiliteColorTabSeven( tabControl );
			border		= GadgetTabControlGetHiliteBorderColorTabSeven( tabControl );
		}
		else
		{//Just enabled
			color			= GadgetTabControlGetEnabledColorTabSeven( tabControl );
			border		= GadgetTabControlGetEnabledBorderColorTabSeven( tabControl );
		}

		// box and border
		if( border != WIN_COLOR_UNDEFINED )
		{
			TheWindowManager->winOpenRect( border, WIN_DRAW_LINE_WIDTH,
																		 tabX, tabY, tabX + tabWidth, tabY + tabHeight );
		}
		if( color != WIN_COLOR_UNDEFINED )
		{
			TheWindowManager->winFillRect( color, WIN_DRAW_LINE_WIDTH,
																		 tabX + 1, tabY + 1, tabX + tabWidth - 1, tabY + tabHeight - 1 );
		}
	}

}

// W3DGadgetRadioButtonImageDraw ==============================================
/** Draw tabs with user supplied images */
//=============================================================================
void W3DGadgetTabControlImageDraw( GameWindow *tabControl,
																	WinInstanceData *instData )
{
	ICoord2D origin, size;

	// get window position and size
	tabControl->winGetScreenPosition( &origin.x, &origin.y );
	tabControl->winGetSize( &size.x, &size.y );

	W3DGameWinDefaultDraw(tabControl, instData);//draw the background

	if( BitIsSet( tabControl->winGetStatus(), WIN_STATUS_BORDER ) == TRUE &&
			!BitIsSet( tabControl->winGetStatus(), WIN_STATUS_SEE_THRU ) )
	{//draw border if desired
		tabControl->winDrawBorder();
	}

	TabControlData *tabData = (TabControlData *)tabControl->winGetUserData();

	Int tabX, tabY, tabWidth, tabHeight, tabDeltaX, tabDeltaY;
	tabX = origin.x + tabData->tabsLeftLimit;
	tabY = origin.y + tabData->tabsTopLimit;
	tabWidth = tabData->tabWidth;
	tabHeight = tabData->tabHeight;
	if( (tabData->tabEdge == TP_TOP_SIDE)  ||  (tabData->tabEdge == TP_BOTTOM_SIDE) )
	{
		tabDeltaX = tabWidth;
		tabDeltaY = 0;
	}
	else
	{
		tabDeltaX = 0;
		tabDeltaY = tabHeight;
	}

	// TheSuperHackers @refactor: Replaced legacy unrolled rendering with dynamic 3-slice pane logic.
	// Added support for 9-slice/tiled backgrounds, and NUM_TAB_PANES tab counts.
	for( Int i = 0; i < tabData->tabCount && i < NUM_TAB_PANES; i++ )
	{
		const Image *leftImage = nullptr;
		const Image *rightImage = nullptr;
		const Image *centerImage = nullptr;

		GameWindow *pane = tabData->subPanes[i];
		if( pane )
		{
			// Query the child TABPANE's instance data instead of the parent TABCONTROL
			WinInstanceData *paneInstData = pane->winGetInstanceData();
			WinDrawData *drawData = nullptr;

			if( tabData->subPaneDisabled[i] )
			{
				drawData = paneInstData->m_disabledDrawData;
			}
			else if( tabData->activeTab == i )
			{
				// Active tab serves as our "Hilited" or "Selected" state
				drawData = paneInstData->m_hiliteDrawData;
			}
			else
			{
				drawData = paneInstData->m_enabledDrawData;
			}

			// Engine standard: Index 0 = Left, 1 = Right, 2 = Center
			if( drawData )
			{
				leftImage   = drawData[0].image;
				rightImage  = drawData[1].image;
				centerImage = drawData[2].image;
			}
		}

		// Render the Tab Button Background
		if( leftImage && rightImage && centerImage )
		{
			// 3-Slice Rendering
			Int leftWidth = leftImage->getImageWidth();
			Int rightWidth = rightImage->getImageWidth();

			// Draw Left
			TheWindowManager->winDrawImage( leftImage, tabX, tabY, tabX + leftWidth, tabY + tabHeight );

			// Draw Right
			TheWindowManager->winDrawImage( rightImage, tabX + tabWidth - rightWidth, tabY, tabX + tabWidth, tabY + tabHeight );

			// Draw Center (Tiled & Clipped to match W3DPushButton behavior exactly)
			Int centerStartX = tabX + leftWidth;
			Int centerEndX = tabX + tabWidth - rightWidth;
			Int centerWidth = centerEndX - centerStartX;

			if( centerWidth > 0 )
			{
				Int imgWidth = centerImage->getImageWidth();
				Int pieces = centerWidth / imgWidth;
				Int currentX = centerStartX;

				// Tile whole pieces
				for( Int p = 0; p < pieces; p++ )
				{
					TheWindowManager->winDrawImage( centerImage, currentX, tabY, currentX + imgWidth, tabY + tabHeight );
					currentX += imgWidth;
				}

				// Clip remainder
				Int remainder = centerEndX - currentX;
				if( remainder > 0 )
				{
					IRegion2D reg;
					reg.lo.x = currentX;
					reg.lo.y = tabY;
					reg.hi.x = centerEndX;
					reg.hi.y = tabY + tabHeight;

					TheDisplay->setClipRegion( &reg );
					TheWindowManager->winDrawImage( centerImage, currentX, tabY, currentX + imgWidth, tabY + tabHeight );
					TheDisplay->enableClipping( FALSE );
				}
			}
		}
		else if( leftImage )
		{
			// Fallback: 1-Slice Stretched (If the .wnd file only provides 1 image)
			TheWindowManager->winDrawImage( leftImage, tabX, tabY, tabX + tabWidth, tabY + tabHeight );
		}

		// Advance position for next tab
		tabX += tabDeltaX;
		tabY += tabDeltaY;
	}
}
