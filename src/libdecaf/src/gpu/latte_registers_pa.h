#pragma once
#include "common/types.h"
#include "common/bitfield.h"
#include "latte_enum_spi.h"
#include "latte_enum_pa.h"

namespace latte
{

// Clipper Control Bits
BITFIELD(PA_CL_CLIP_CNTL, uint32_t)
   BITFIELD_ENTRY(0, 1, bool, UCP_ENA_0);
   BITFIELD_ENTRY(1, 1, bool, UCP_ENA_1);
   BITFIELD_ENTRY(2, 1, bool, UCP_ENA_2);
   BITFIELD_ENTRY(3, 1, bool, UCP_ENA_3);
   BITFIELD_ENTRY(4, 1, bool, UCP_ENA_4);
   BITFIELD_ENTRY(5, 1, bool, UCP_ENA_5);
   BITFIELD_ENTRY(13, 1, bool, PS_UCP_Y_SCALE_NEG);
   BITFIELD_ENTRY(14, 2, PA_PS_UCP_MODE, PS_UCP_MODE);
   BITFIELD_ENTRY(16, 1, bool, CLIP_DISABLE);
   BITFIELD_ENTRY(17, 1, bool, UCP_CULL_ONLY_ENA);
   BITFIELD_ENTRY(18, 1, bool, BOUNDARY_EDGE_FLAG_ENA);
   BITFIELD_ENTRY(19, 1, bool, DX_CLIP_SPACE_DEF);
   BITFIELD_ENTRY(20, 1, bool, DIS_CLIP_ERR_DETECT);
   BITFIELD_ENTRY(21, 1, bool, VTX_KILL_OR);
   BITFIELD_ENTRY(22, 1, bool, RASTERISER_DISABLE);
   BITFIELD_ENTRY(24, 1, bool, DX_LINEAR_ATTR_CLIP_ENA);
   BITFIELD_ENTRY(25, 1, bool, VTE_VPORT_PROVOKE_DISABLE);
   BITFIELD_ENTRY(26, 1, bool, ZCLIP_NEAR_DISABLE);
   BITFIELD_ENTRY(27, 1, bool, ZCLIP_FAR_DISABLE);
BITFIELD_END

// Horizontal Guard Band Clip Adjust Register
union PA_CL_GB_HORZ_CLIP_ADJ
{
   uint32_t value;
   float DATA_REGISTER;
};

// Horizontal Guard Band Discard Adjust Register
union PA_CL_GB_HORZ_DISC_ADJ
{
   uint32_t value;
   float DATA_REGISTER;
};

// Vertical Guard Band Clip Adjust Register
union PA_CL_GB_VERT_CLIP_ADJ
{
   uint32_t value;
   float DATA_REGISTER;
};

// Vertical Guard Band Discard Adjust Register
union PA_CL_GB_VERT_DISC_ADJ
{
   uint32_t value;
   float DATA_REGISTER;
};

// Viewport Transform X Scale Factor
union PA_CL_VPORT_XSCALE_N
{
   uint32_t value;
   float VPORT_XSCALE;
};

using PA_CL_VPORT_XSCALE_0 = PA_CL_VPORT_XSCALE_N;
using PA_CL_VPORT_XSCALE_1 = PA_CL_VPORT_XSCALE_N;
using PA_CL_VPORT_XSCALE_2 = PA_CL_VPORT_XSCALE_N;
using PA_CL_VPORT_XSCALE_3 = PA_CL_VPORT_XSCALE_N;
using PA_CL_VPORT_XSCALE_4 = PA_CL_VPORT_XSCALE_N;
using PA_CL_VPORT_XSCALE_5 = PA_CL_VPORT_XSCALE_N;
using PA_CL_VPORT_XSCALE_6 = PA_CL_VPORT_XSCALE_N;
using PA_CL_VPORT_XSCALE_7 = PA_CL_VPORT_XSCALE_N;
using PA_CL_VPORT_XSCALE_8 = PA_CL_VPORT_XSCALE_N;
using PA_CL_VPORT_XSCALE_9 = PA_CL_VPORT_XSCALE_N;
using PA_CL_VPORT_XSCALE_10 = PA_CL_VPORT_XSCALE_N;
using PA_CL_VPORT_XSCALE_11 = PA_CL_VPORT_XSCALE_N;
using PA_CL_VPORT_XSCALE_12 = PA_CL_VPORT_XSCALE_N;
using PA_CL_VPORT_XSCALE_13 = PA_CL_VPORT_XSCALE_N;
using PA_CL_VPORT_XSCALE_14 = PA_CL_VPORT_XSCALE_N;
using PA_CL_VPORT_XSCALE_15 = PA_CL_VPORT_XSCALE_N;

// Viewport Transform X Offset
union PA_CL_VPORT_XOFFSET_N
{
   uint32_t value;
   float VPORT_XOFFSET;
};

using PA_CL_VPORT_XOFFSET_0 = PA_CL_VPORT_XOFFSET_N;
using PA_CL_VPORT_XOFFSET_1 = PA_CL_VPORT_XOFFSET_N;
using PA_CL_VPORT_XOFFSET_2 = PA_CL_VPORT_XOFFSET_N;
using PA_CL_VPORT_XOFFSET_3 = PA_CL_VPORT_XOFFSET_N;
using PA_CL_VPORT_XOFFSET_4 = PA_CL_VPORT_XOFFSET_N;
using PA_CL_VPORT_XOFFSET_5 = PA_CL_VPORT_XOFFSET_N;
using PA_CL_VPORT_XOFFSET_6 = PA_CL_VPORT_XOFFSET_N;
using PA_CL_VPORT_XOFFSET_7 = PA_CL_VPORT_XOFFSET_N;
using PA_CL_VPORT_XOFFSET_8 = PA_CL_VPORT_XOFFSET_N;
using PA_CL_VPORT_XOFFSET_9 = PA_CL_VPORT_XOFFSET_N;
using PA_CL_VPORT_XOFFSET_10 = PA_CL_VPORT_XOFFSET_N;
using PA_CL_VPORT_XOFFSET_11 = PA_CL_VPORT_XOFFSET_N;
using PA_CL_VPORT_XOFFSET_12 = PA_CL_VPORT_XOFFSET_N;
using PA_CL_VPORT_XOFFSET_13 = PA_CL_VPORT_XOFFSET_N;
using PA_CL_VPORT_XOFFSET_14 = PA_CL_VPORT_XOFFSET_N;
using PA_CL_VPORT_XOFFSET_15 = PA_CL_VPORT_XOFFSET_N;

// Viewport Transform Y Scale Factor
union PA_CL_VPORT_YSCALE_N
{
   uint32_t value;
   float VPORT_YSCALE;
};

using PA_CL_VPORT_YSCALE_0 = PA_CL_VPORT_YSCALE_N;
using PA_CL_VPORT_YSCALE_1 = PA_CL_VPORT_YSCALE_N;
using PA_CL_VPORT_YSCALE_2 = PA_CL_VPORT_YSCALE_N;
using PA_CL_VPORT_YSCALE_3 = PA_CL_VPORT_YSCALE_N;
using PA_CL_VPORT_YSCALE_4 = PA_CL_VPORT_YSCALE_N;
using PA_CL_VPORT_YSCALE_5 = PA_CL_VPORT_YSCALE_N;
using PA_CL_VPORT_YSCALE_6 = PA_CL_VPORT_YSCALE_N;
using PA_CL_VPORT_YSCALE_7 = PA_CL_VPORT_YSCALE_N;
using PA_CL_VPORT_YSCALE_8 = PA_CL_VPORT_YSCALE_N;
using PA_CL_VPORT_YSCALE_9 = PA_CL_VPORT_YSCALE_N;
using PA_CL_VPORT_YSCALE_10 = PA_CL_VPORT_YSCALE_N;
using PA_CL_VPORT_YSCALE_11 = PA_CL_VPORT_YSCALE_N;
using PA_CL_VPORT_YSCALE_12 = PA_CL_VPORT_YSCALE_N;
using PA_CL_VPORT_YSCALE_13 = PA_CL_VPORT_YSCALE_N;
using PA_CL_VPORT_YSCALE_14 = PA_CL_VPORT_YSCALE_N;
using PA_CL_VPORT_YSCALE_15 = PA_CL_VPORT_YSCALE_N;

// Viewport Transform Y Offset
union PA_CL_VPORT_YOFFSET_N
{
   uint32_t value;
   float VPORT_YOFFSET;
};

using PA_CL_VPORT_YOFFSET_0 = PA_CL_VPORT_YOFFSET_N;
using PA_CL_VPORT_YOFFSET_1 = PA_CL_VPORT_YOFFSET_N;
using PA_CL_VPORT_YOFFSET_2 = PA_CL_VPORT_YOFFSET_N;
using PA_CL_VPORT_YOFFSET_3 = PA_CL_VPORT_YOFFSET_N;
using PA_CL_VPORT_YOFFSET_4 = PA_CL_VPORT_YOFFSET_N;
using PA_CL_VPORT_YOFFSET_5 = PA_CL_VPORT_YOFFSET_N;
using PA_CL_VPORT_YOFFSET_6 = PA_CL_VPORT_YOFFSET_N;
using PA_CL_VPORT_YOFFSET_7 = PA_CL_VPORT_YOFFSET_N;
using PA_CL_VPORT_YOFFSET_8 = PA_CL_VPORT_YOFFSET_N;
using PA_CL_VPORT_YOFFSET_9 = PA_CL_VPORT_YOFFSET_N;
using PA_CL_VPORT_YOFFSET_10 = PA_CL_VPORT_YOFFSET_N;
using PA_CL_VPORT_YOFFSET_11 = PA_CL_VPORT_YOFFSET_N;
using PA_CL_VPORT_YOFFSET_12 = PA_CL_VPORT_YOFFSET_N;
using PA_CL_VPORT_YOFFSET_13 = PA_CL_VPORT_YOFFSET_N;
using PA_CL_VPORT_YOFFSET_14 = PA_CL_VPORT_YOFFSET_N;
using PA_CL_VPORT_YOFFSET_15 = PA_CL_VPORT_YOFFSET_N;

// Viewport Transform Z Scale Factor
union PA_CL_VPORT_ZSCALE_N
{
   uint32_t value;
   float VPORT_ZSCALE;
};

using PA_CL_VPORT_ZSCALE_0 = PA_CL_VPORT_ZSCALE_N;
using PA_CL_VPORT_ZSCALE_1 = PA_CL_VPORT_ZSCALE_N;
using PA_CL_VPORT_ZSCALE_2 = PA_CL_VPORT_ZSCALE_N;
using PA_CL_VPORT_ZSCALE_3 = PA_CL_VPORT_ZSCALE_N;
using PA_CL_VPORT_ZSCALE_4 = PA_CL_VPORT_ZSCALE_N;
using PA_CL_VPORT_ZSCALE_5 = PA_CL_VPORT_ZSCALE_N;
using PA_CL_VPORT_ZSCALE_6 = PA_CL_VPORT_ZSCALE_N;
using PA_CL_VPORT_ZSCALE_7 = PA_CL_VPORT_ZSCALE_N;
using PA_CL_VPORT_ZSCALE_8 = PA_CL_VPORT_ZSCALE_N;
using PA_CL_VPORT_ZSCALE_9 = PA_CL_VPORT_ZSCALE_N;
using PA_CL_VPORT_ZSCALE_10 = PA_CL_VPORT_ZSCALE_N;
using PA_CL_VPORT_ZSCALE_11 = PA_CL_VPORT_ZSCALE_N;
using PA_CL_VPORT_ZSCALE_12 = PA_CL_VPORT_ZSCALE_N;
using PA_CL_VPORT_ZSCALE_13 = PA_CL_VPORT_ZSCALE_N;
using PA_CL_VPORT_ZSCALE_14 = PA_CL_VPORT_ZSCALE_N;
using PA_CL_VPORT_ZSCALE_15 = PA_CL_VPORT_ZSCALE_N;

// Viewport Transform Z Offset
union PA_CL_VPORT_ZOFFSET_N
{
   uint32_t value;
   float VPORT_ZOFFSET;
};

using PA_CL_VPORT_ZOFFSET_0 = PA_CL_VPORT_ZOFFSET_N;
using PA_CL_VPORT_ZOFFSET_1 = PA_CL_VPORT_ZOFFSET_N;
using PA_CL_VPORT_ZOFFSET_2 = PA_CL_VPORT_ZOFFSET_N;
using PA_CL_VPORT_ZOFFSET_3 = PA_CL_VPORT_ZOFFSET_N;
using PA_CL_VPORT_ZOFFSET_4 = PA_CL_VPORT_ZOFFSET_N;
using PA_CL_VPORT_ZOFFSET_5 = PA_CL_VPORT_ZOFFSET_N;
using PA_CL_VPORT_ZOFFSET_6 = PA_CL_VPORT_ZOFFSET_N;
using PA_CL_VPORT_ZOFFSET_7 = PA_CL_VPORT_ZOFFSET_N;
using PA_CL_VPORT_ZOFFSET_8 = PA_CL_VPORT_ZOFFSET_N;
using PA_CL_VPORT_ZOFFSET_9 = PA_CL_VPORT_ZOFFSET_N;
using PA_CL_VPORT_ZOFFSET_10 = PA_CL_VPORT_ZOFFSET_N;
using PA_CL_VPORT_ZOFFSET_11 = PA_CL_VPORT_ZOFFSET_N;
using PA_CL_VPORT_ZOFFSET_12 = PA_CL_VPORT_ZOFFSET_N;
using PA_CL_VPORT_ZOFFSET_13 = PA_CL_VPORT_ZOFFSET_N;
using PA_CL_VPORT_ZOFFSET_14 = PA_CL_VPORT_ZOFFSET_N;
using PA_CL_VPORT_ZOFFSET_15 = PA_CL_VPORT_ZOFFSET_N;

// Vertex Shader Output Control
BITFIELD(PA_CL_VS_OUT_CNTL, uint32_t)
   BITFIELD_ENTRY(0, 1, bool, CLIP_DIST_ENA_0);
   BITFIELD_ENTRY(1, 1, bool, CLIP_DIST_ENA_1);
   BITFIELD_ENTRY(2, 1, bool, CLIP_DIST_ENA_2);
   BITFIELD_ENTRY(3, 1, bool, CLIP_DIST_ENA_3);
   BITFIELD_ENTRY(4, 1, bool, CLIP_DIST_ENA_4);
   BITFIELD_ENTRY(5, 1, bool, CLIP_DIST_ENA_5);
   BITFIELD_ENTRY(6, 1, bool, CLIP_DIST_ENA_6);
   BITFIELD_ENTRY(7, 1, bool, CLIP_DIST_ENA_7);
   BITFIELD_ENTRY(8, 1, bool, CULL_DIST_ENA_0);
   BITFIELD_ENTRY(9, 1, bool, CULL_DIST_ENA_1);
   BITFIELD_ENTRY(10, 1, bool, CULL_DIST_ENA_2);
   BITFIELD_ENTRY(11, 1, bool, CULL_DIST_ENA_3);
   BITFIELD_ENTRY(12, 1, bool, CULL_DIST_ENA_4);
   BITFIELD_ENTRY(13, 1, bool, CULL_DIST_ENA_5);
   BITFIELD_ENTRY(14, 1, bool, CULL_DIST_ENA_6);
   BITFIELD_ENTRY(15, 1, bool, CULL_DIST_ENA_7);
   BITFIELD_ENTRY(16, 1, bool, USE_VTX_POINT_SIZE);
   BITFIELD_ENTRY(17, 1, bool, USE_VTX_EDGE_FLAG);
   BITFIELD_ENTRY(18, 1, bool, USE_VTX_RENDER_TARGET_INDX);
   BITFIELD_ENTRY(19, 1, bool, USE_VTX_VIEWPORT_INDX);
   BITFIELD_ENTRY(20, 1, bool, USE_VTX_KILL_FLAG);
   BITFIELD_ENTRY(21, 1, bool, VS_OUT_MISC_VEC_ENA);
   BITFIELD_ENTRY(22, 1, bool, VS_OUT_CCDIST0_VEC_ENA);
   BITFIELD_ENTRY(23, 1, bool, VS_OUT_CCDIST1_VEC_ENA);
   BITFIELD_ENTRY(24, 1, bool, VS_OUT_MISC_SIDE_BUS_ENA);
   BITFIELD_ENTRY(25, 1, bool, USE_VTX_GS_CUT_FLAG);
BITFIELD_END

// Multisample AA Mask
BITFIELD(PA_SC_AA_MASK, uint32_t)
   BITFIELD_ENTRY(0, 8, uint32_t, AA_MASK_ULC);
   BITFIELD_ENTRY(0, 8, uint32_t, AA_MASK_URC);
   BITFIELD_ENTRY(0, 8, uint32_t, AA_MASK_LLC);
   BITFIELD_ENTRY(0, 8, uint32_t, AA_MASK_LRC);
BITFIELD_END

// Generic Scissor rectangle specification
BITFIELD(PA_SC_GENERIC_SCISSOR_BR, uint32_t)
   BITFIELD_ENTRY(0, 14, uint32_t, BR_X);
   BITFIELD_ENTRY(16, 14, uint32_t, BR_Y);
BITFIELD_END

// Generic Scissor rectangle specification
BITFIELD(PA_SC_GENERIC_SCISSOR_TL, uint32_t)
   BITFIELD_ENTRY(0, 14, uint32_t, TL_X);
   BITFIELD_ENTRY(16, 14, uint32_t, TL_Y);
   BITFIELD_ENTRY(31, 1, uint32_t, WINDOW_OFFSET_DISABLE);
BITFIELD_END

// Viewport Transform Z Min Clamp
union PA_SC_VPORT_ZMIN_N
{
   uint32_t value;
   float VPORT_ZMIN;
};

using PA_SC_VPORT_ZMIN_0 = PA_SC_VPORT_ZMIN_N;
using PA_SC_VPORT_ZMIN_1 = PA_SC_VPORT_ZMIN_N;
using PA_SC_VPORT_ZMIN_2 = PA_SC_VPORT_ZMIN_N;
using PA_SC_VPORT_ZMIN_3 = PA_SC_VPORT_ZMIN_N;
using PA_SC_VPORT_ZMIN_4 = PA_SC_VPORT_ZMIN_N;
using PA_SC_VPORT_ZMIN_5 = PA_SC_VPORT_ZMIN_N;
using PA_SC_VPORT_ZMIN_6 = PA_SC_VPORT_ZMIN_N;
using PA_SC_VPORT_ZMIN_7 = PA_SC_VPORT_ZMIN_N;
using PA_SC_VPORT_ZMIN_8 = PA_SC_VPORT_ZMIN_N;
using PA_SC_VPORT_ZMIN_9 = PA_SC_VPORT_ZMIN_N;
using PA_SC_VPORT_ZMIN_10 = PA_SC_VPORT_ZMIN_N;
using PA_SC_VPORT_ZMIN_11 = PA_SC_VPORT_ZMIN_N;
using PA_SC_VPORT_ZMIN_12 = PA_SC_VPORT_ZMIN_N;
using PA_SC_VPORT_ZMIN_13 = PA_SC_VPORT_ZMIN_N;
using PA_SC_VPORT_ZMIN_14 = PA_SC_VPORT_ZMIN_N;
using PA_SC_VPORT_ZMIN_15 = PA_SC_VPORT_ZMIN_N;

// Viewport Transform Z Max Clamp
union PA_SC_VPORT_ZMAX_N
{
   uint32_t value;
   float VPORT_ZMAX;
};

using PA_SC_VPORT_ZMAX_0 = PA_SC_VPORT_ZMAX_N;
using PA_SC_VPORT_ZMAX_1 = PA_SC_VPORT_ZMAX_N;
using PA_SC_VPORT_ZMAX_2 = PA_SC_VPORT_ZMAX_N;
using PA_SC_VPORT_ZMAX_3 = PA_SC_VPORT_ZMAX_N;
using PA_SC_VPORT_ZMAX_4 = PA_SC_VPORT_ZMAX_N;
using PA_SC_VPORT_ZMAX_5 = PA_SC_VPORT_ZMAX_N;
using PA_SC_VPORT_ZMAX_6 = PA_SC_VPORT_ZMAX_N;
using PA_SC_VPORT_ZMAX_7 = PA_SC_VPORT_ZMAX_N;
using PA_SC_VPORT_ZMAX_8 = PA_SC_VPORT_ZMAX_N;
using PA_SC_VPORT_ZMAX_9 = PA_SC_VPORT_ZMAX_N;
using PA_SC_VPORT_ZMAX_10 = PA_SC_VPORT_ZMAX_N;
using PA_SC_VPORT_ZMAX_11 = PA_SC_VPORT_ZMAX_N;
using PA_SC_VPORT_ZMAX_12 = PA_SC_VPORT_ZMAX_N;
using PA_SC_VPORT_ZMAX_13 = PA_SC_VPORT_ZMAX_N;
using PA_SC_VPORT_ZMAX_14 = PA_SC_VPORT_ZMAX_N;
using PA_SC_VPORT_ZMAX_15 = PA_SC_VPORT_ZMAX_N;

// Line control
BITFIELD(PA_SU_LINE_CNTL, uint32_t)
   BITFIELD_ENTRY(0, 16, uint32_t, WIDTH); // 16.0 fixed
BITFIELD_END

// Specifies maximum and minimum point & sprite sizes for per vertex size specification
BITFIELD(PA_SU_POINT_MINMAX, uint32_t)
   BITFIELD_ENTRY(0, 16, uint32_t, MIN_SIZE); // 12.4 fixed
   BITFIELD_ENTRY(16, 16, uint32_t, MAX_SIZE); // 12.4 fixed
BITFIELD_END

// Dimensions for Points
BITFIELD(PA_SU_POINT_SIZE, uint32_t)
   BITFIELD_ENTRY(0, 16, uint32_t, HEIGHT); // 12.4 fixed
   BITFIELD_ENTRY(16, 16, uint32_t, WIDTH); // 12.4 fixed
BITFIELD_END

// Clamp Value for Polygon Offset
union PA_SU_POLY_OFFSET_CLAMP
{
   uint32_t value;
   float CLAMP;
};

// Back-Facing Polygon Offset Scale
union PA_SU_POLY_OFFSET_BACK_SCALE
{
   uint32_t value;
   float SCALE;
};

// Back-Facing Polygon Offset Scale
union PA_SU_POLY_OFFSET_BACK_OFFSET
{
   uint32_t value;
   float OFFSET;
};

// Front-Facing Polygon Offset Scale
union PA_SU_POLY_OFFSET_FRONT_SCALE
{
   uint32_t value;
   float SCALE;
};

// Front-Facing Polygon Offset Scale
union PA_SU_POLY_OFFSET_FRONT_OFFSET
{
   uint32_t value;
   float OFFSET;
};

// SU/SC Controls for Facedness Culling, Polymode, Polygon Offset, and various Enables
BITFIELD(PA_SU_SC_MODE_CNTL, uint32_t)
   BITFIELD_ENTRY(0, 1, bool, CULL_FRONT);
   BITFIELD_ENTRY(1, 1, bool, CULL_BACK);
   BITFIELD_ENTRY(2, 1, PA_FACE, FACE);
   BITFIELD_ENTRY(3, 2, uint32_t, POLY_MODE);
   BITFIELD_ENTRY(5, 3, uint32_t, POLYMODE_FRONT_PTYPE);
   BITFIELD_ENTRY(8, 3, uint32_t, POLYMODE_BACK_PTYPE);
   BITFIELD_ENTRY(11, 1, bool, POLY_OFFSET_FRONT_ENABLE);
   BITFIELD_ENTRY(12, 1, bool, POLY_OFFSET_BACK_ENABLE);
   BITFIELD_ENTRY(13, 1, bool, POLY_OFFSET_PARA_ENABLE);
   BITFIELD_ENTRY(16, 1, bool, VTX_WINDOW_OFFSET_ENABLE);
   BITFIELD_ENTRY(19, 1, bool, PROVOKING_VTX_LAST);
   BITFIELD_ENTRY(20, 1, bool, PERSP_CORR_DIS);
   BITFIELD_ENTRY(21, 1, bool, MULTI_PRIM_IB_ENA);
BITFIELD_END

// Polygon Offset Depth Buffer Format Control
BITFIELD(PA_SU_POLY_OFFSET_DB_FMT_CNTL, uint32_t)
   BITFIELD_ENTRY(0, 8, uint32_t, POLY_OFFSET_NEG_NUM_DB_BITS);
   BITFIELD_ENTRY(8, 1, uint32_t, POLY_OFFSET_DB_IS_FLOAT_FMT);
BITFIELD_END

} // namespace latte
