#pragma once
#include "common/types.h"

namespace latte
{

enum SQ_ALU_ENCODING : uint32_t
{
   SQ_ALU_OP2                       = 0,
   SQ_ALU_OP3                       = 1,
};

enum SQ_ALU_EXECUTE_MASK_OP : uint32_t
{
   SQ_ALU_EXECUTE_MASK_OP_DEACTIVATE   = 0,
   SQ_ALU_EXECUTE_MASK_OP_BREAK        = 1,
   SQ_ALU_EXECUTE_MASK_OP_CONTINUE     = 2,
   SQ_ALU_EXECUTE_MASK_OP_KILL         = 3,
};

enum SQ_ALU_OMOD : uint32_t
{
   SQ_ALU_OMOD_OFF                  = 0,
   SQ_ALU_OMOD_M2                   = 1,
   SQ_ALU_OMOD_M4                   = 2,
   SQ_ALU_OMOD_D2                   = 3,
};

enum SQ_ALU_SRC : uint32_t
{
   SQ_ALU_REGISTER_FIRST            = 0,
   SQ_ALU_REGISTER_LAST             = 127,
   SQ_ALU_KCACHE_BANK0_FIRST        = 128,
   SQ_ALU_KCACHE_BANK0_LAST         = 159,
   SQ_ALU_KCACHE_BANK1_FIRST        = 160,
   SQ_ALU_KCACHE_BANK1_LAST         = 191,
   SQ_ALU_SRC_LDS_OQ_A              = 219,
   SQ_ALU_SRC_LDS_OQ_B              = 220,
   SQ_ALU_SRC_LDS_OQ_A_POP          = 221,
   SQ_ALU_SRC_LDS_OQ_B_POP          = 222,
   SQ_ALU_SRC_LDS_DIRECT_A          = 223,
   SQ_ALU_SRC_LDS_DIRECT_B          = 224,
   SQ_ALU_SRC_TIME_HI               = 227,
   SQ_ALU_SRC_TIME_LO               = 228,
   SQ_ALU_SRC_MASK_HI               = 229,
   SQ_ALU_SRC_MASK_LO               = 230,
   SQ_ALU_SRC_HW_WAVE_ID            = 231,
   SQ_ALU_SRC_SIMD_ID               = 232,
   SQ_ALU_SRC_SE_ID                 = 233,
   SQ_ALU_SRC_HW_THREADGRP_ID       = 234,
   SQ_ALU_SRC_WAVE_ID_IN_GRP        = 235,
   SQ_ALU_SRC_NUM_THREADGRP_WAVES   = 236,
   SQ_ALU_SRC_HW_ALU_ODD            = 237,
   SQ_ALU_SRC_LOOP_IDX              = 238,
   SQ_ALU_SRC_PARAM_BASE_ADDR       = 240,
   SQ_ALU_SRC_NEW_PRIM_MASK         = 241,
   SQ_ALU_SRC_PRIM_MASK_HI          = 242,
   SQ_ALU_SRC_PRIM_MASK_LO          = 243,
   SQ_ALU_SRC_1_DBL_L               = 244,
   SQ_ALU_SRC_1_DBL_M               = 245,
   SQ_ALU_SRC_0_5_DBL_L             = 246,
   SQ_ALU_SRC_0_5_DBL_M             = 247,
   SQ_ALU_SRC_0                     = 248,
   SQ_ALU_SRC_1                     = 249,
   SQ_ALU_SRC_1_INT                 = 250,
   SQ_ALU_SRC_M_1_INT               = 251,
   SQ_ALU_SRC_0_5                   = 252,
   SQ_ALU_SRC_LITERAL               = 253,
   SQ_ALU_SRC_PV                    = 254,
   SQ_ALU_SRC_PS                    = 255,
   SQ_ALU_SRC_CONST_FILE_FIRST      = 256,
   SQ_ALU_SRC_CONST_FILE_LAST       = 511,
};

enum SQ_ALU_VEC_BANK_SWIZZLE : uint32_t
{
   SQ_ALU_VEC_012                   = 0,
   SQ_ALU_VEC_021                   = 1,
   SQ_ALU_VEC_120                   = 2,
   SQ_ALU_VEC_102                   = 3,
   SQ_ALU_VEC_201                   = 4,
   SQ_ALU_VEC_210                   = 5,
   SQ_ALU_SCL_210                   = 0,
   SQ_ALU_SCL_122                   = 1,
   SQ_ALU_SCL_212                   = 2,
   SQ_ALU_SCL_221                   = 3,
};

enum SQ_CF_COND : uint32_t
{
   SQ_CF_COND_ACTIVE                = 0,
   SQ_CF_COND_FALSE                 = 1,
   SQ_CF_COND_BOOL                  = 2,
   SQ_CF_COND_NOT_BOOL              = 3,
};

enum SQ_DATA_FORMAT : uint32_t
{
   FMT_INVALID                      = 0,
   FMT_8                            = 1,
   FMT_4_4                          = 2,
   FMT_3_3_2                        = 3,
   FMT_16                           = 5,
   FMT_16_FLOAT                     = 6,
   FMT_8_8                          = 7,
   FMT_5_6_5                        = 8,
   FMT_6_5_5                        = 9,
   FMT_1_5_5_5                      = 10,
   FMT_4_4_4_4                      = 11,
   FMT_5_5_5_1                      = 12,
   FMT_32                           = 13,
   FMT_32_FLOAT                     = 14,
   FMT_16_16                        = 15,
   FMT_16_16_FLOAT                  = 16,
   FMT_8_24                         = 17,
   FMT_8_24_FLOAT                   = 18,
   FMT_24_8                         = 19,
   FMT_24_8_FLOAT                   = 20,
   FMT_10_11_11                     = 21,
   FMT_10_11_11_FLOAT               = 22,
   FMT_11_11_10                     = 23,
   FMT_11_11_10_FLOAT               = 24,
   FMT_2_10_10_10                   = 25,
   FMT_8_8_8_8                      = 26,
   FMT_10_10_10_2                   = 27,
   FMT_X24_8_32_FLOAT               = 28,
   FMT_32_32                        = 29,
   FMT_32_32_FLOAT                  = 30,
   FMT_16_16_16_16                  = 31,
   FMT_16_16_16_16_FLOAT            = 32,
   FMT_32_32_32_32                  = 34,
   FMT_32_32_32_32_FLOAT            = 35,
   FMT_1                            = 37,
   FMT_GB_GR                        = 39,
   FMT_BG_RG                        = 40,
   FMT_32_AS_8                      = 41,
   FMT_32_AS_8_8                    = 42,
   FMT_5_9_9_9_SHAREDEXP            = 43,
   FMT_8_8_8                        = 44,
   FMT_16_16_16                     = 45,
   FMT_16_16_16_FLOAT               = 46,
   FMT_32_32_32                     = 47,
   FMT_32_32_32_FLOAT               = 48,
   FMT_BC1                          = 49,
   FMT_BC2                          = 50,
   FMT_BC3                          = 51,
   FMT_BC4                          = 52,
   FMT_BC5                          = 53,
   FMT_APC0                         = 54,
   FMT_APC1                         = 55,
   FMT_APC2                         = 56,
   FMT_APC3                         = 57,
   FMT_APC4                         = 58,
   FMT_APC5                         = 59,
   FMT_APC6                         = 60,
   FMT_APC7                         = 61,
   FMT_CTX1                         = 62,
   FMT_MASK                         = 0x3F,
};

enum SQ_EXPORT_TYPE : uint32_t
{
   SQ_EXPORT_PIXEL                  = 0,
   SQ_EXPORT_POS                    = 1,
   SQ_EXPORT_PARAM                  = 2,
   SQ_EXPORT_WRITE                  = 0,
   SQ_EXPORT_WRITE_IND              = 1,
   SQ_EXPORT_READ                   = 2,
   SQ_EXPORT_READ_IND               = 3,
};

enum SQ_CF_KCACHE_MODE : uint32_t
{
   SQ_CF_KCACHE_NOP                 = 0,
   SQ_CF_KCACHE_LOCK_1              = 1,
   SQ_CF_KCACHE_LOCK_2              = 2,
   SQ_CF_KCACHE_LOCK_LOOP_INDEX     = 3,
};

enum SQ_CHAN : uint32_t
{
   SQ_CHAN_X                        = 0,
   SQ_CHAN_Y                        = 1,
   SQ_CHAN_Z                        = 2,
   SQ_CHAN_W                        = 3,
   SQ_CHAN_T                        = 4,
};

enum SQ_ENDIAN : uint32_t
{
   SQ_ENDIAN_NONE                   = 0,
   SQ_ENDIAN_8IN16                  = 1,
   SQ_ENDIAN_8IN32                  = 2,
   SQ_ENDIAN_AUTO                   = 3,
};

enum SQ_FORMAT_COMP : uint32_t
{
   SQ_FORMAT_COMP_UNSIGNED          = 0,
   SQ_FORMAT_COMP_SIGNED            = 1,
};

enum SQ_INDEX_MODE : uint32_t
{
   SQ_INDEX_AR_X                    = 0,
   SQ_INDEX_AR_Y                    = 1,
   SQ_INDEX_AR_Z                    = 2,
   SQ_INDEX_AR_W                    = 3,
   SQ_INDEX_LOOP                    = 4,
};

enum SQ_NUM_FORMAT : uint32_t
{
   SQ_NUM_FORMAT_NORM               = 0,
   SQ_NUM_FORMAT_INT                = 1,
   SQ_NUM_FORMAT_SCALED             = 2,
};

enum SQ_PRED_SEL : uint32_t
{
   SQ_PRED_SEL_OFF                  = 0,
   SQ_PRED_SEL_ZERO                 = 2,
   SQ_PRED_SEL_ONE                  = 3,
};

enum SQ_SRF_MODE : uint32_t
{
   SQ_SRF_MODE_ZERO_CLAMP_MINUS_ONE = 0,
   SQ_SRF_MODE_NO_ZERO              = 1,
};

enum SQ_REL : uint32_t
{
   SQ_ABSOLUTE                      = 0,
   SQ_RELATIVE                      = 1,
};

enum SQ_RES_OFFSET
{
   SQ_PS_RESOURCE_BASE        = 0x0,
   SQ_VS_RESOURCE_BASE        = 0xA0,
   SQ_GS_RESOURCE_BASE        = 0x150,

   SQ_PS_TEX_RESOURCE_0       = 0x0,
   SQ_PS_BUF_RESOURCE_0       = 0x80,
   SQ_VS_TEX_RESOURCE_0       = 0xA0,
   SQ_VS_BUF_RESOURCE_0       = 0x120,
   SQ_VS_GSOUT_RESOURCE       = 0x13F,
   SQ_VS_ATTRIB_RESOURCE_0    = 0x140,
   SQ_GS_TEX_RESOURCE_0       = 0x150,
   SQ_GS_BUF_RESOURCE_0       = 0x1D0,
   SQ_GS_GSIN_RESOURCE        = 0x1EF,
};

enum SQ_SEL : uint32_t
{
   SQ_SEL_X                         = 0,
   SQ_SEL_Y                         = 1,
   SQ_SEL_Z                         = 2,
   SQ_SEL_W                         = 3,
   SQ_SEL_0                         = 4,
   SQ_SEL_1                         = 5,
   SQ_SEL_MASK                      = 7,
};

enum SQ_TEX_COORD_TYPE : uint32_t
{
   SQ_TEX_UNNORMALIZED              = 0,
   SQ_TEX_NORMALIZED                = 1,
};

enum SQ_TEX_DIM : uint32_t
{
   SQ_TEX_DIM_1D                    = 0,
   SQ_TEX_DIM_2D                    = 1,
   SQ_TEX_DIM_3D                    = 2,
   SQ_TEX_DIM_CUBEMAP               = 3,
   SQ_TEX_DIM_1D_ARRAY              = 4,
   SQ_TEX_DIM_2D_ARRAY              = 5,
   SQ_TEX_DIM_2D_MSAA               = 6,
   SQ_TEX_DIM_2D_ARRAY_MSAA         = 7,
};

enum SQ_TEX_VTX_TYPE : uint32_t
{
   SQ_TEX_VTX_INVALID_TEXTURE       = 0,
   SQ_TEX_VTX_INVALID_BUFFER        = 1,
   SQ_TEX_VTX_VALID_TEXTURE         = 2,
   SQ_TEX_VTX_VALID_BUFFER          = 3,
};

enum SQ_TILE_MODE : uint32_t
{
   SQ_TILE_MODE_DEFAULT         = 0,
   SQ_TILE_MODE_LINEAR_ALIGNED  = 1,
   SQ_TILE_MODE_TILED_1D_THIN1  = 2,
   SQ_TILE_MODE_TILED_1D_THICK  = 3,
   SQ_TILE_MODE_TILED_2D_THIN1  = 4,
   SQ_TILE_MODE_TILED_2D_THIN2  = 5,
   SQ_TILE_MODE_TILED_2D_THIN4  = 6,
   SQ_TILE_MODE_TILED_2D_THICK  = 7,
   SQ_TILE_MODE_TILED_2B_THIN1  = 8,
   SQ_TILE_MODE_TILED_2B_THIN2  = 9,
   SQ_TILE_MODE_TILED_2B_THIN4  = 10,
   SQ_TILE_MODE_TILED_2B_THICK  = 11,
   SQ_TILE_MODE_TILED_3D_THIN1  = 12,
   SQ_TILE_MODE_TILED_3D_THICK  = 13,
   SQ_TILE_MODE_TILED_3B_THIN1  = 14,
   SQ_TILE_MODE_TILED_3B_THICK  = 15,
   SQ_TILE_MODE_LINEAR_SPECIAL  = 16,
};

enum SQ_VTX_CLAMP : uint32_t
{
   SQ_VTX_CLAMP_ZERO                = 0,
   SQ_VTX_CLAMP_NAN                 = 1,
};

enum SQ_VTX_FETCH_TYPE : uint32_t
{
   SQ_VTX_FETCH_VERTEX_DATA         = 0,
   SQ_VTX_FETCH_INSTANCE_DATA       = 1,
   SQ_VTX_FETCH_NO_INDEX_OFFSET     = 2,
};

enum SQ_TEX_CLAMP : uint32_t
{
   SQ_TEX_WRAP = 0,
   SQ_TEX_MIRROR = 1,
   SQ_TEX_CLAMP_LAST_TEXEL = 2,
   SQ_TEX_MIRROR_ONCE_LAST_TEXEL = 3,
   SQ_TEX_CLAMP_HALF_BORDER = 4,
   SQ_TEX_MIRROR_ONCE_HALF_BORDER = 5,
   SQ_TEX_CLAMP_BORDER = 6,
   SQ_TEX_MIRROR_ONCE_BORDER = 7,
};

enum SQ_TEX_ANISO : uint32_t
{
   SQ_TEX_ANISO_1_TO_1 = 0,
   SQ_TEX_ANISO_2_TO_1 = 1,
   SQ_TEX_ANISO_4_TO_1 = 2,
   SQ_TEX_ANISO_8_TO_1 = 3,
   SQ_TEX_ANISO_16_TO_1 = 4,
};

enum SQ_TEX_BORDER_COLOR : uint32_t
{
   SQ_TEX_BORDER_COLOR_TRANS_BLACK = 0,
   SQ_TEX_BORDER_COLOR_OPAQUE_BLACK = 1,
   SQ_TEX_BORDER_COLOR_OPAQUE_WHITE = 2,
   SQ_TEX_BORDER_COLOR_REGISTER = 3,
};

enum SQ_TEX_CHROMA_KEY : uint32_t
{
   SQ_TEX_CHROMA_KEY_DISABLED = 0,
   SQ_TEX_CHROMA_KEY_KILL = 1,
   SQ_TEX_CHROMA_KEY_BLEND = 2,
};

enum SQ_TEX_DEPTH_COMPARE : uint32_t
{
   SQ_TEX_DEPTH_COMPARE_NEVER = 0,
   SQ_TEX_DEPTH_COMPARE_LESS = 1,
   SQ_TEX_DEPTH_COMPARE_EQUAL = 2,
   SQ_TEX_DEPTH_COMPARE_LESSEQUAL = 3,
   SQ_TEX_DEPTH_COMPARE_GREATER = 4,
   SQ_TEX_DEPTH_COMPARE_NOTEQUAL = 5,
   SQ_TEX_DEPTH_COMPARE_GREATEREQUAL = 6,
   SQ_TEX_DEPTH_COMPARE_ALWAYS = 7,
};

enum SQ_TEX_MPEG_CLAMP : uint32_t
{
   SQ_TEX_MPEG_CLAMP_OFF            = 0,
   SQ_TEX_MPEG_9                    = 1,
   SQ_TEX_MPEG_10                   = 2,
};

enum SQ_TEX_ROUNDING_MODE : uint32_t
{
   SQ_TEX_ROUNDING_TRUNCATE = 0,
   SQ_TEX_ROUNDING_NEAREST_EVEN = 1,
};

enum SQ_TEX_XY_FILTER : uint32_t
{
   SQ_TEX_XY_FILTER_POINT = 0,
   SQ_TEX_XY_FILTER_BILINEAR = 1,
   SQ_TEX_XY_FILTER_BICUBIC = 2,
};

enum SQ_TEX_Z_FILTER : uint32_t
{
   SQ_TEX_Z_FILTER_NONE = 0,
   SQ_TEX_Z_FILTER_POINT = 1,
   SQ_TEX_Z_FILTER_LINEAR = 2,
};

} // namespace latte
