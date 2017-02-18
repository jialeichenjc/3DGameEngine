#include "CreateGameObject.h"
#include "assert.h"
#include "lua.hpp"
uint8_t * LoadFile(const char * i_pFilename, size_t & o_sizeFile);
size_t ReadFloatArray(lua_State * i_pState, int i_index, float * o_pFloats, size_t i_numFloats);

GameObject* create_game_object(const char * i_pScriptFilename) {
	
	GameObject *p_game_obj = nullptr;
	
	// Initialize us a lua_State                         
	lua_State * pLuaState = luaL_newstate();
	assert(pLuaState);

	luaL_openlibs(pLuaState);


	// Read in a file
	size_t			sizeFile = 0;
	uint8_t *		pFileContents = LoadFile("Data\\Player.lua", sizeFile);

	// Read in the player game object info

	if (pFileContents  && sizeFile)
	{
		int			result = 0;

		// Do the initial buffer parsing
		result = luaL_loadbuffer(pLuaState, reinterpret_cast<char *>(pFileContents), sizeFile, nullptr);
		assert(result == 0);
		lua_pcall(pLuaState, 0, 0, 0);
		assert(result == 0);

		int			type = LUA_TNIL;

		// Find the global variable named "Player" and push it onto stack.
		// If it doesn't find it it pushes a nil value instead
		result = lua_getglobal(pLuaState, "Player");
		assert(result == LUA_TTABLE);

		// Get the Actor name from the Player table
		// 1. Push the key string
		lua_pushstring(pLuaState, "name");

		// 2. Get the value associated with the key
		type = lua_gettable(pLuaState, -2);
		assert(type == LUA_TSTRING);
		const char * pName = lua_tostring(pLuaState, -1);
		assert(pName != NULL);
		if (pName)
			pName = _strdup(pName);

		// 3. Remove the value from the stack now that we're done with it
		lua_pop(pLuaState, 1);

		// Get the GameObject's inital position from the Player table
		lua_pushstring(pLuaState, "initial_position");
		type = lua_gettable(pLuaState, -2);
		assert(type == LUA_TTABLE);

		float position[2] = { 0.0f };

		ReadFloatArray(pLuaState, -1, position, 2);
		assert(position[0] == 0.0f);
		assert(position[1] == 0.0f);
		// we're done with the "initial_position table - pop it
		lua_pop(pLuaState, 1);
	}



	return p_game_obj;
}

uint8_t * LoadFile(const char * i_pFilename, size_t & o_sizeFile)
{
	assert(i_pFilename != NULL);

	FILE *				pFile = NULL;

	errno_t fopenError = fopen_s(&pFile, i_pFilename, "rb");
	if (fopenError != 0)
		return NULL;

	assert(pFile != NULL);

	int FileIOError = fseek(pFile, 0, SEEK_END);
	assert(FileIOError == 0);

	long FileSize = ftell(pFile);
	assert(FileSize >= 0);

	FileIOError = fseek(pFile, 0, SEEK_SET);
	assert(FileIOError == 0);

	uint8_t * pBuffer = new uint8_t[FileSize];
	assert(pBuffer);

	size_t FileRead = fread(pBuffer, 1, FileSize, pFile);
	assert(FileRead == FileSize);

	fclose(pFile);

	o_sizeFile = FileSize;

	return pBuffer;
}

size_t ReadFloatArray(lua_State * i_pState, int i_index, float * o_pFloats, size_t i_numFloats)
{
	assert(i_pState);
	assert(lua_gettop(i_pState) >= -i_index);
	assert(lua_type(i_pState, i_index) == LUA_TTABLE);

	size_t index = 0;

	lua_pushnil(i_pState);

	while (lua_next(i_pState, i_index - 1) != 0)
	{
		if (lua_type(i_pState, -1) == LUA_TNUMBER)
		{
			o_pFloats[index] = float(lua_tonumber(i_pState, -1));
		}
		else
		{
			// DEBUG_PRINT( "Expected a number at position %d while reading table as float array.\n", index );
		}

		// pop the value now that we've retrieved it
		lua_pop(i_pState, 1);
		if (++index == i_numFloats)
		{
			lua_pop(i_pState, 1);
			break;
		}
	}
	return index;
}
