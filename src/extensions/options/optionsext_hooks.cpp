/*******************************************************************************
/*                 O P E N  S O U R C E  --  V I N I F E R A                  **
/*******************************************************************************
 *
 *  @project       Vinifera
 *
 *  @file          OPTIONSEXT_HOOKS.CPP
 *
 *  @author        CCHyper
 *
 *  @brief         Contains the hooks for the extended OptionsClass.
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
#include "optionsext_hooks.h"
#include "optionsext_init.h"
#include "optionsext.h"
#include "fatal.h"
#include "debughandler.h"
#include "asserthandler.h"
#include "hooker.h"
#include "hooker_macros.h"
#include "rawfile.h"


/**
 *  Patches Hotkey_Dialog_Proc to use RawFileClass when deleting Keyboard.INI to ensure only
 *  the file in the game's root directory is deleted.
 *
 *  @author: ZivDero
 */
void _Delete_Keyboard_INI()
{
    RawFileClass keyboard_ini("Keyboard.ini");
    keyboard_ini.Delete();
}

DECLARE_PATCH(_Hotkey_Dialog_Proc_Keyboard_INI_RawFileClass_Patch)
{
    _Delete_Keyboard_INI();
    JMP(0x0058AA21);
}


/**
 *  Main function for patching the hooks.
 */
void OptionsClassExtension_Hooks()
{
    /**
     *  Initialises the extended class.
     */
    OptionsClassExtension_Init();

    Patch_Jump(0x0058AA18, &_Hotkey_Dialog_Proc_Keyboard_INI_RawFileClass_Patch);
}
