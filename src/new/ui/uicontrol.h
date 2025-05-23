/*******************************************************************************
/*                 O P E N  S O U R C E  --  V I N I F E R A                  **
/*******************************************************************************
 *
 *  @project       Vinifera
 *
 *  @file          UICONTROL.H
 *
 *  @author        CCHyper
 *
 *  @brief         UI controls and overrides.
 *
 *  @license       Vinifera is free software: you can redistribute it and/or
 *                 modify it under the terms of the GNU General Public License
 *                 as published by the Free Software Foundation, either version
 *                 3 of the License, or (at your option) any later version.
 *
 *                 Vinifera is distributed in the hope that it will be
 *                 useful, but WITHOUT ANY WARRANTY; without even the implied
 *                 warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *                 PURPOSE. See the GNU General Public License for more details.
 *
 *                 You should have received a copy of the GNU General Public
 *                 License along with this program.
 *                 If not, see <http://www.gnu.org/licenses/>.
 *
 ******************************************************************************/
#pragma once

#include "always.h"
#include "tibsun_defines.h"
#include "point.h"
#include "typelist.h"


struct IStream;
class CCINIClass;
class NoInitClass;


class UIControlsClass
{
    public:
        UIControlsClass();
        UIControlsClass(const NoInitClass &noinit);
        ~UIControlsClass();

        HRESULT Load(IStream *pStm);
        HRESULT Save(IStream *pStm, BOOL fClearDirty);
        int Get_Object_Size() const;

        bool Read_INI(CCINIClass &ini);

        /**
         *  Helper to get the group number drawing offset based on the object type.
         */
        TPoint2D<int> Get_Group_Number_Offset(RTTIType type, bool has_pip) const
        {
            switch (type)
            {
            case RTTI_UNIT:
            case RTTI_UNITTYPE:
                return has_pip ? UnitWithPipGroupNumberOffset : UnitGroupNumberOffset;
            case RTTI_INFANTRY:
            case RTTI_INFANTRYTYPE:
                return has_pip ? InfantryWithPipGroupNumberOffset : InfantryGroupNumberOffset;
            case RTTI_BUILDING:
            case RTTI_BUILDINGTYPE:
                return has_pip ? BuildingWithPipGroupNumberOffset : BuildingGroupNumberOffset;
            case RTTI_AIRCRAFT:
            case RTTI_AIRCRAFTTYPE:
                return has_pip ? AircraftWithPipGroupNumberOffset : AircraftGroupNumberOffset;
            default:
                return TPoint2D<int>();
            }
        }

        /**
         *  Helper to get the veterancy pip drawing offset based on the object type.
         */
        TPoint2D<int> Get_Veterancy_Pip_Offset(RTTIType type) const
        {
            switch (type)
            {
            case RTTI_UNIT:
            case RTTI_UNITTYPE:
                return UnitVeterancyPipOffset;
            case RTTI_INFANTRY:
            case RTTI_INFANTRYTYPE:
                return InfantryVeterancyPipOffset;
            case RTTI_BUILDING:
            case RTTI_BUILDINGTYPE:
                return BuildingVeterancyPipOffset;
            case RTTI_AIRCRAFT:
            case RTTI_AIRCRAFTTYPE:
                return AircraftVeterancyPipOffset;
            default:
                return TPoint2D<int>();
            }
        }

        /**
         *  Helper to get the special pip drawing offset based on the object type.
         */
        TPoint2D<int> Get_Special_Pip_Offset(RTTIType type) const
        {
            switch (type)
            {
            case RTTI_UNIT:
            case RTTI_UNITTYPE:
                return UnitSpecialPipOffset;
            case RTTI_INFANTRY:
            case RTTI_INFANTRYTYPE:
                return InfantrySpecialPipOffset;
            case RTTI_BUILDING:
            case RTTI_BUILDINGTYPE:
                return BuildingSpecialPipOffset;
            case RTTI_AIRCRAFT:
            case RTTI_AIRCRAFTTYPE:
                return AircraftSpecialPipOffset;
            default:
                return TPoint2D<int>();
            }
        }

    public:
        /**
         *  Health bar draw positions.
         */
        TPoint2D<int> UnitHealthBarDrawPos;
        TPoint2D<int> InfantryHealthBarDrawPos;

        /**
         *  Should the text label be drawn with an outline?
         */
        bool IsTextLabelOutline;

        /**
         *  Transparency of the text background.
         */
        unsigned TextLabelBackgroundTransparency;

        /**
         *  Customizable offsets for drawing different pips.
         */
        TPoint2D<int> UnitGroupNumberOffset;
        TPoint2D<int> InfantryGroupNumberOffset;
        TPoint2D<int> BuildingGroupNumberOffset;
        TPoint2D<int> AircraftGroupNumberOffset;
        TPoint2D<int> UnitWithPipGroupNumberOffset;
        TPoint2D<int> InfantryWithPipGroupNumberOffset;
        TPoint2D<int> BuildingWithPipGroupNumberOffset;
        TPoint2D<int> AircraftWithPipGroupNumberOffset;
        TPoint2D<int> UnitVeterancyPipOffset;
        TPoint2D<int> InfantryVeterancyPipOffset;
        TPoint2D<int> BuildingVeterancyPipOffset;
        TPoint2D<int> AircraftVeterancyPipOffset;
        TPoint2D<int> UnitSpecialPipOffset;
        TPoint2D<int> InfantrySpecialPipOffset;
        TPoint2D<int> BuildingSpecialPipOffset;
        TPoint2D<int> AircraftSpecialPipOffset;

        /**
         *  Should the tactical rubber band box be drawn with a drop shadow?
         */
        bool IsBandBoxDropShadow;

        /**
         *  Should the tactical rubber band box be drawn with a thick border?
         */
        bool IsBandBoxThick;

        /**
         *  Color to draw the tactical rubber band box with.
         */
        RGBStruct BandBoxColor;

        /**
         *  Color to draw the tactical rubber band box's shadow with.
         */
        RGBStruct BandBoxDropShadowColor;

        /**
         *  Transparency of the tactical rubber band.
         */
        unsigned BandBoxTintTransparency;

        /**
         *  Two tint colors, interpolated between based on the current ambient light level.
         */
        TypeList<RGBStruct> BandBoxTintColors;

        /**
         *  Should action lines remain visible continuously, instead of disappearing after some time?
         */
        bool IsAlwaysShowActionLines;

        /**
         *  Should movement lines be drawn with dashes?
         */
        bool IsMovementLineDashed;

        /**
         *  Should movement lines be drawn with a drop shadow?
         */
        bool IsMovementLineDropShadow;

        /**
         *  Should movement lines be drawn with a thick line?
         */
        bool IsMovementLineThick;

        /**
         *  Color to draw movement lines with.
         */
        RGBStruct MovementLineColor;

        /**
         *  Color to draw movement lines' drop shadow with.
         */
        RGBStruct MovementLineDropShadowColor;

        /**
         *  Should target lines be drawn with dashes?
         */
        bool IsTargetLineDashed;

        /**
         *  Should target lines be drawn with a drop shadow?
         */
        bool IsTargetLineDropShadow;

        /**
         *  Should target lines be drawn with a thick line?
         */
        bool IsTargetLineThick;

        /**
         *  Color to target movement lines with.
         */
        RGBStruct TargetLineColor;

        /**
         *  Color to draw target lines' drop shadow with.
         */
        RGBStruct TargetLineDropShadowColor;

        /**
         *  Should target laser be drawn with dashes?
         */
        bool IsTargetLaserDashed;

        /**
         *  Should target laser be drawn with a drop shadow?
         */
        bool IsTargetLaserDropShadow;

        /**
         *  Should target laser be drawn with a thick line?
         */
        bool IsTargetLaserThick;

        /**
         *  Color to draw the target laser with.
         */
        RGBStruct TargetLaserColor;

        /**
         *  Color to draw the target laser's drop shadow with.
         */
        RGBStruct TargetLaserDropShadowColor;

        /**
         *  Time in frames the target laser should be drawn for when the unit fires.
         */
        unsigned TargetLaserTime;

        /**
         *  Should NavCom queue lines be displayed?
         */
        bool IsShowNavComQueueLines;

        /**
         *  Should NavCom queue lines be drawn with dashes?
         */
        bool IsNavComQueueLineDashed;

        /**
         *  Should NavCom queue lines be drawn with a drop shadow?
         */
        bool IsNavComQueueLineDropShadow;

        /**
         *  Should NavCom queue lines be drawn with a thick line?
         */
        bool IsNavComQueueLineThick;

        /**
         *  Color to draw the NavCom queue lines with.
         */
        RGBStruct NavComQueueLineColor;

        /**
         *  Color to draw the NavCom queue lines' drop shadow with.
         */
        RGBStruct NavComQueueLineDropShadowColor;

        /**
         *  Should the sidebar repair, etc. buttons use the old X position, centered on the radar?
         */
        bool IsCenterSidebarButtonsOnRadar;
};

extern UIControlsClass *UIControls;
