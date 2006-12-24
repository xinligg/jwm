/**
 * @file key.h
 * @author Joe Wingbermuehle
 * @date 2004-2006
 *
 * @brief Header for the key binding functions.
 *
 */

#ifndef KEY_H
#define KEY_H

struct ClientNode;

/** Enumeration of key binding types. */
typedef enum {
   KEY_NONE         = 0,
   KEY_UP           = 1,
   KEY_DOWN         = 2,
   KEY_RIGHT        = 3,
   KEY_LEFT         = 4,
   KEY_ESC          = 5,
   KEY_ENTER        = 6,
   KEY_NEXT         = 7,
   KEY_NEXT_STACKED = 8,
   KEY_CLOSE        = 9,
   KEY_MIN          = 10,
   KEY_MAX          = 11,
   KEY_SHADE        = 12,
   KEY_MOVE         = 13,
   KEY_RESIZE       = 14,
   KEY_ROOT         = 15,
   KEY_WIN          = 16,
   KEY_DESKTOP      = 17,
   KEY_EXEC         = 18,
   KEY_RESTART      = 19,
   KEY_EXIT         = 20
} KeyType;

void InitializeKeys();
void StartupKeys();
void ShutdownKeys();
void DestroyKeys();

/** Get the action to take from a key event.
 * @param event The event.
 */
KeyType GetKey(const XKeyEvent *event);

/** Grab keys on a client window.
 * @param np The client.
 */
void GrabKeys(struct ClientNode *np);

/** Insert a key binding.
 * @param key The key binding type.
 * @param modifiers The modifier mask.
 * @param stroke The key stroke (not needed if code given).
 * @param code The key code (not needed if stroke given).
 * @param command Extra parameter needed for some key binding types.
 */
void InsertBinding(KeyType key, const char *modifiers,
   const char *stroke, const char *code, const char *command);

/** Run a command caused by a key binding.
 * @param event The event causing the command to be run.
 */
void RunKeyCommand(const XKeyEvent *event);

/** Show a root menu caused by a key binding.
 * @param event The event that caused the menu to be shown.
 */
void ShowKeyMenu(const XKeyEvent *event);

/** Validate key bindings.
 * This will log an error if an invalid key binding is found.
 * This is called after parsing the configuration file.
 */
void ValidateKeys();

#endif /* KEY_H */

