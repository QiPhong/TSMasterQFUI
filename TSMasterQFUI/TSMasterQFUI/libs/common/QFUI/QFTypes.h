#pragma once
typedef float QREAL;
typedef int  INT;
typedef float REAL;
typedef void QBrush;
#define REAL_EPSILON        1.192092896e-07F        /* FLT_EPSILON */
#ifndef IN
#define IN
#endif
#ifndef OUT
#define OUT
#endif
#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif
class QSizeF
{
public:
    QSizeF()
    {
        Width = Height = 0.0f;
    }

    QSizeF(IN const QSizeF& size)
    {
        Width = size.Width;
        Height = size.Height;
    }

    QSizeF(IN REAL width,
          IN REAL height)
    {
        Width = width;
        Height = height;
    }

    QSizeF operator+(IN const QSizeF& sz) const
    {
        return QSizeF(Width + sz.Width,
                     Height + sz.Height);
    }

    QSizeF operator-(IN const QSizeF& sz) const
    {
        return QSizeF(Width - sz.Width,
                     Height - sz.Height);
    }

    BOOL Equals(IN const QSizeF& sz) const
    {
        return (Width == sz.Width) && (Height == sz.Height);
    }

    BOOL Empty() const
    {
        return (Width == 0.0f && Height == 0.0f);
    }

public:

    REAL Width;
    REAL Height;
};
class QSize
{
public:
    QSize()
    {
        Width = Height = 0;
    }

    QSize(IN const QSize& size)
    {
        Width = size.Width;
        Height = size.Height;
    }

    QSize(IN INT width,
         IN INT height)
    {
        Width = width;
        Height = height;
    }

    QSize operator+(IN const QSize& sz) const
    {
        return QSize(Width + sz.Width,
                    Height + sz.Height);
    }

    QSize operator-(IN const QSize& sz) const
    {
        return QSize(Width - sz.Width,
                    Height - sz.Height);
    }

    BOOL Equals(IN const QSize& sz) const
    {
        return (Width == sz.Width) && (Height == sz.Height);
    }

    BOOL Empty() const
    {
        return (Width == 0 && Height == 0);
    }

public:

    INT Width;
    INT Height;
};

class QPointF
{
public:
   QPointF()
   {
       X = Y = 0.0f;
   }

   QPointF(IN const QPointF &point)
   {
       X = point.X;
       Y = point.Y;
   }

   QPointF(IN const QSizeF &size)
   {
       X = size.Width;
       Y = size.Height;
   }

   QPointF(IN REAL x,
          IN REAL y)
   {
       X = x;
       Y = y;
   }

   QPointF operator+(IN const QPointF& point) const
   {
       return QPointF(X + point.X,
                     Y + point.Y);
   }

   QPointF operator-(IN const QPointF& point) const
   {
       return QPointF(X - point.X,
                     Y - point.Y);
   }

   BOOL Equals(IN const QPointF& point)
   {
       return (X == point.X) && (Y == point.Y);
   }

public:

    REAL X;
    REAL Y;
};

class QPoint
{
public:
   QPoint()
   {
       X = Y = 0;
   }

   QPoint(IN const QPoint &point)
   {
       X = point.X;
       Y = point.Y;
   }

   QPoint(IN const QSize &size)
   {
       X = size.Width;
       Y = size.Height;
   }

   QPoint(IN INT x,
         IN INT y)
   {
       X = x;
       Y = y;
   }

   QPoint operator+(IN const QPoint& point) const
   {
       return QPoint(X + point.X,
                    Y + point.Y);
   }

   QPoint operator-(IN const QPoint& point) const
   {
       return QPoint(X - point.X,
                    Y - point.Y);
   }

   BOOL Equals(IN const QPoint& point)
   {
       return (X == point.X) && (Y == point.Y);
   }

public:

    INT X;
    INT Y;
};

//--------------------------------------------------------------------------
// Represents a rectangle in a 2D coordinate system (floating-point coordinates)
//--------------------------------------------------------------------------

class QRectF
{
public:

    QRectF()
    {
        X = Y = Width = Height = 0.0f;
    }

    QRectF(IN REAL x,
          IN REAL y,
          IN REAL width,
          IN REAL height)
    {
        X = x;
        Y = y;
        Width = width;
        Height = height;
    }

    QRectF(IN const QPointF& location,
          IN const QSizeF& size)
    {
        X = location.X;
        Y = location.Y;
        Width = size.Width;
        Height = size.Height;
    }

    QRectF* Clone() const
    {
        return new QRectF(X, Y, Width, Height);
    }

    VOID GetLocation(OUT QPointF* point) const
    {
        point->X = X;
        point->Y = Y;
    }

    VOID GetSize(OUT QSizeF* size) const
    {
        size->Width = Width;
        size->Height = Height;
    }

    VOID GetBounds(OUT QRectF* rect) const
    {
        rect->X = X;
        rect->Y = Y;
        rect->Width = Width;
        rect->Height = Height;
    }

    REAL GetLeft() const
    {
        return X;
    }

    REAL GetTop() const
    {
        return Y;
    }

    REAL GetRight() const
    {
        return X+Width;
    }

    REAL GetBottom() const
    {
        return Y+Height;
    }

    BOOL IsEmptyArea() const
    {
        return (Width <= REAL_EPSILON) || (Height <= REAL_EPSILON);
    }

    BOOL Equals(IN const QRectF & rect) const
    {
        return X == rect.X &&
               Y == rect.Y &&
               Width == rect.Width &&
               Height == rect.Height;
    }

    BOOL Contains(IN REAL x,
                  IN REAL y) const
    {
        return x >= X && x < X+Width &&
               y >= Y && y < Y+Height;
    }

    BOOL Contains(IN const QPointF& pt) const
    {
        return Contains(pt.X, pt.Y);
    }

    BOOL Contains(IN const QRectF& rect) const
    {
        return (X <= rect.X) && (rect.GetRight() <= GetRight()) &&
               (Y <= rect.Y) && (rect.GetBottom() <= GetBottom());
    }

    VOID Inflate(IN REAL dx,
                 IN REAL dy)
    {
        X -= dx;
        Y -= dy;
        Width += 2*dx;
        Height += 2*dy;
    }

    VOID Inflate(IN const QPointF& point)
    {
        Inflate(point.X, point.Y);
    }

    BOOL Intersect(IN const QRectF& rect)
    {
        return Intersect(*this, *this, rect);
    }

    static BOOL Intersect(OUT QRectF& c,
                          IN const QRectF& a,
                          IN const QRectF& b)
    {
        REAL right = min(a.GetRight(), b.GetRight());
        REAL bottom = min(a.GetBottom(), b.GetBottom());
        REAL left = max(a.GetLeft(), b.GetLeft());
        REAL top = max(a.GetTop(), b.GetTop());

        c.X = left;
        c.Y = top;
        c.Width = right - left;
        c.Height = bottom - top;
        return !c.IsEmptyArea();
    }

    BOOL IntersectsWith(IN const QRectF& rect) const
    {
        return (GetLeft() < rect.GetRight() &&
                GetTop() < rect.GetBottom() &&
                GetRight() > rect.GetLeft() &&
                GetBottom() > rect.GetTop());
    }

    static BOOL Union(OUT QRectF& c,
                      IN const QRectF& a,
                      IN const QRectF& b)
    {
        REAL right = max(a.GetRight(), b.GetRight());
        REAL bottom = max(a.GetBottom(), b.GetBottom());
        REAL left = min(a.GetLeft(), b.GetLeft());
        REAL top = min(a.GetTop(), b.GetTop());

        c.X = left;
        c.Y = top;
        c.Width = right - left;
        c.Height = bottom - top;
        return !c.IsEmptyArea();
    }

    VOID Offset(IN const QPointF& point)
    {
        Offset(point.X, point.Y);
    }

    VOID Offset(IN REAL dx,
                IN REAL dy)
    {
        X += dx;
        Y += dy;
    }

public:

    REAL X;
    REAL Y;
    REAL Width;
    REAL Height;
};

class QRect
{
public:

    QRect()
    {
        X = Y = Width = Height = 0;
    }

    QRect(IN INT x,
         IN INT y,
         IN INT width,
         IN INT height)
    {
        X = x;
        Y = y;
        Width = width;
        Height = height;
    }

    QRect(IN const QPoint& location,
         IN const QSize& size)
    {
        X = location.X;
        Y = location.Y;
        Width = size.Width;
        Height = size.Height;
    }

    QRect* Clone() const
    {
        return new QRect(X, Y, Width, Height);
    }

    VOID GetLocation(OUT QPoint* point) const
    {
        point->X = X;
        point->Y = Y;
    }

    VOID GetSize(OUT QSize* size) const
    {
        size->Width = Width;
        size->Height = Height;
    }

    VOID GetBounds(OUT QRect* rect) const
    {
        rect->X = X;
        rect->Y = Y;
        rect->Width = Width;
        rect->Height = Height;
    }

    INT GetLeft() const
    {
        return X;
    }

    INT GetTop() const
    {
        return Y;
    }

    INT GetRight() const
    {
        return X+Width;
    }

    INT GetBottom() const
    {
        return Y+Height;
    }

    BOOL IsEmptyArea() const
    {
        return (Width <= 0) || (Height <= 0);
    }

    BOOL Equals(IN const QRect & rect) const
    {
        return X == rect.X &&
               Y == rect.Y &&
               Width == rect.Width &&
               Height == rect.Height;
    }

    BOOL Contains(IN INT x,
                  IN INT y) const
    {
        return x >= X && x < X+Width &&
               y >= Y && y < Y+Height;
    }

    BOOL Contains(IN const QPoint& pt) const
    {
        return Contains(pt.X, pt.Y);
    }

    BOOL Contains(IN QRect& rect) const
    {
        return (X <= rect.X) && (rect.GetRight() <= GetRight()) &&
               (Y <= rect.Y) && (rect.GetBottom() <= GetBottom());
    }

    VOID Inflate(IN INT dx,
                 IN INT dy)
    {
        X -= dx;
        Y -= dy;
        Width += 2*dx;
        Height += 2*dy;
    }

    VOID Inflate(IN const QPoint& point)
    {
        Inflate(point.X, point.Y);
    }

    BOOL Intersect(IN const QRect& rect)
    {
        return Intersect(*this, *this, rect);
    }

    static BOOL Intersect(OUT QRect& c,
                          IN const QRect& a,
                          IN const QRect& b)
    {
        INT right = min(a.GetRight(), b.GetRight());
        INT bottom = min(a.GetBottom(), b.GetBottom());
        INT left = max(a.GetLeft(), b.GetLeft());
        INT top = max(a.GetTop(), b.GetTop());

        c.X = left;
        c.Y = top;
        c.Width = right - left;
        c.Height = bottom - top;
        return !c.IsEmptyArea();
    }

    BOOL IntersectsWith(IN const QRect& rect) const
    {
        return (GetLeft() < rect.GetRight() &&
                GetTop() < rect.GetBottom() &&
                GetRight() > rect.GetLeft() &&
                GetBottom() > rect.GetTop());
    }

    static BOOL Union(OUT QRect& c,
                      IN const QRect& a,
                      IN const QRect& b)
    {
        INT right = max(a.GetRight(), b.GetRight());
        INT bottom = max(a.GetBottom(), b.GetBottom());
        INT left = min(a.GetLeft(), b.GetLeft());
        INT top = min(a.GetTop(), b.GetTop());

        c.X = left;
        c.Y = top;
        c.Width = right - left;
        c.Height = bottom - top;
        return !c.IsEmptyArea();
    }

    VOID Offset(IN const QPoint& point)
    {
        Offset(point.X, point.Y);
    }

    VOID Offset(IN INT dx,
                IN INT dy)
    {
        X += dx;
        Y += dy;
    }

public:

    INT X;
    INT Y;
    INT Width;
    INT Height;
};
//typedef unsigned long  DWORD;
//typedef DWORD COLORREF;
typedef DWORD ARGB;
//typedef unsigned char BYTE;
//typedef unsigned short  WORD;
//typedef unsigned __int64 ULONG_PTR, *PULONG_PTR;
//typedef ULONG_PTR DWORD_PTR, *PDWORD_PTR;
#ifndef LOBYTE
#define LOBYTE(w)           ((BYTE)(((DWORD_PTR)(w)) & 0xff))
#endif
#ifndef HIBYTE
#define HIBYTE(w)           ((BYTE)((((DWORD_PTR)(w)) >> 8) & 0xff))
#endif
#ifndef GetRValue
#define GetRValue(rgb)      (LOBYTE(rgb))
#endif
#ifndef GetGValue
#define GetGValue(rgb)      (LOBYTE(((WORD)(rgb)) >> 8))
#endif
#ifndef GetBValue
#define GetBValue(rgb)      (LOBYTE((rgb)>>16))
#endif
#ifndef RGB
#define RGB(r,g,b)          ((COLORREF)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))
#endif
class QColor
{
public:

    QColor()
    {
        Argb = (ARGB)QColor::Black;
    }



    QColor(IN BYTE r,
          IN BYTE g,
          IN BYTE b)
    {
        Argb = MakeARGB(255, r, g, b);
    }

    QColor(IN BYTE a,
          IN BYTE r,
          IN BYTE g,
          IN BYTE b)
    {
        Argb = MakeARGB(a, r, g, b);
    }

    QColor(IN ARGB argb)
    {
        Argb = argb;
    }

    BYTE GetAlpha() const
    {
        return (BYTE) (Argb >> AlphaShift);
    }

    BYTE GetA() const
    {
        return GetAlpha();
    }

    BYTE GetRed() const
    {
        return (BYTE) (Argb >> RedShift);
    }

    BYTE GetR() const
    {
        return GetRed();
    }

    BYTE GetGreen() const
    {
        return (BYTE) (Argb >> GreenShift);
    }

    BYTE GetG() const
    {
        return GetGreen();
    }

    BYTE GetBlue() const
    {
        return (BYTE) (Argb >> BlueShift);
    }

    BYTE GetB() const
    {
        return GetBlue();
    }

    ARGB GetValue() const
    {
        return Argb;
    }

    VOID SetValue(IN ARGB argb)
    {
        Argb = argb;
    }

    VOID SetFromCOLORREF(IN COLORREF rgb)
    {
        Argb = MakeARGB(255, GetRValue(rgb), GetGValue(rgb), GetBValue(rgb));
    }

    COLORREF ToCOLORREF() const
    {
        return RGB(GetRed(), GetGreen(), GetBlue());
    }

public:

    // Common color constants
    
    enum
    {
        AliceBlue            = 0xFFF0F8FF,
        AntiqueWhite         = 0xFFFAEBD7,
        Aqua                 = 0xFF00FFFF,
        Aquamarine           = 0xFF7FFFD4,
        Azure                = 0xFFF0FFFF,
        Beige                = 0xFFF5F5DC,
        Bisque               = 0xFFFFE4C4,
        Black                = 0xFF000000,
        BlanchedAlmond       = 0xFFFFEBCD,
        Blue                 = 0xFF0000FF,
        BlueViolet           = 0xFF8A2BE2,
        Brown                = 0xFFA52A2A,
        BurlyWood            = 0xFFDEB887,
        CadetBlue            = 0xFF5F9EA0,
        Chartreuse           = 0xFF7FFF00,
        Chocolate            = 0xFFD2691E,
        Coral                = 0xFFFF7F50,
        CornflowerBlue       = 0xFF6495ED,
        Cornsilk             = 0xFFFFF8DC,
        Crimson              = 0xFFDC143C,
        Cyan                 = 0xFF00FFFF,
        DarkBlue             = 0xFF00008B,
        DarkCyan             = 0xFF008B8B,
        DarkGoldenrod        = 0xFFB8860B,
        DarkGray             = 0xFFA9A9A9,
        DarkGreen            = 0xFF006400,
        DarkKhaki            = 0xFFBDB76B,
        DarkMagenta          = 0xFF8B008B,
        DarkOliveGreen       = 0xFF556B2F,
        DarkOrange           = 0xFFFF8C00,
        DarkOrchid           = 0xFF9932CC,
        DarkRed              = 0xFF8B0000,
        DarkSalmon           = 0xFFE9967A,
        DarkSeaGreen         = 0xFF8FBC8B,
        DarkSlateBlue        = 0xFF483D8B,
        DarkSlateGray        = 0xFF2F4F4F,
        DarkTurquoise        = 0xFF00CED1,
        DarkViolet           = 0xFF9400D3,
        DeepPink             = 0xFFFF1493,
        DeepSkyBlue          = 0xFF00BFFF,
        DimGray              = 0xFF696969,
        DodgerBlue           = 0xFF1E90FF,
        Firebrick            = 0xFFB22222,
        FloralWhite          = 0xFFFFFAF0,
        ForestGreen          = 0xFF228B22,
        Fuchsia              = 0xFFFF00FF,
        Gainsboro            = 0xFFDCDCDC,
        GhostWhite           = 0xFFF8F8FF,
        Gold                 = 0xFFFFD700,
        Goldenrod            = 0xFFDAA520,
        Gray                 = 0xFF808080,
        Green                = 0xFF008000,
        GreenYellow          = 0xFFADFF2F,
        Honeydew             = 0xFFF0FFF0,
        HotPink              = 0xFFFF69B4,
        IndianRed            = 0xFFCD5C5C,
        Indigo               = 0xFF4B0082,
        Ivory                = 0xFFFFFFF0,
        Khaki                = 0xFFF0E68C,
        Lavender             = 0xFFE6E6FA,
        LavenderBlush        = 0xFFFFF0F5,
        LawnGreen            = 0xFF7CFC00,
        LemonChiffon         = 0xFFFFFACD,
        LightBlue            = 0xFFADD8E6,
        LightCoral           = 0xFFF08080,
        LightCyan            = 0xFFE0FFFF,
        LightGoldenrodYellow = 0xFFFAFAD2,
        LightGray            = 0xFFD3D3D3,
        LightGreen           = 0xFF90EE90,
        LightPink            = 0xFFFFB6C1,
        LightSalmon          = 0xFFFFA07A,
        LightSeaGreen        = 0xFF20B2AA,
        LightSkyBlue         = 0xFF87CEFA,
        LightSlateGray       = 0xFF778899,
        LightSteelBlue       = 0xFFB0C4DE,
        LightYellow          = 0xFFFFFFE0,
        Lime                 = 0xFF00FF00,
        LimeGreen            = 0xFF32CD32,
        Linen                = 0xFFFAF0E6,
        Magenta              = 0xFFFF00FF,
        Maroon               = 0xFF800000,
        MediumAquamarine     = 0xFF66CDAA,
        MediumBlue           = 0xFF0000CD,
        MediumOrchid         = 0xFFBA55D3,
        MediumPurple         = 0xFF9370DB,
        MediumSeaGreen       = 0xFF3CB371,
        MediumSlateBlue      = 0xFF7B68EE,
        MediumSpringGreen    = 0xFF00FA9A,
        MediumTurquoise      = 0xFF48D1CC,
        MediumVioletRed      = 0xFFC71585,
        MidnightBlue         = 0xFF191970,
        MintCream            = 0xFFF5FFFA,
        MistyRose            = 0xFFFFE4E1,
        Moccasin             = 0xFFFFE4B5,
        NavajoWhite          = 0xFFFFDEAD,
        Navy                 = 0xFF000080,
        OldLace              = 0xFFFDF5E6,
        Olive                = 0xFF808000,
        OliveDrab            = 0xFF6B8E23,
        Orange               = 0xFFFFA500,
        OrangeRed            = 0xFFFF4500,
        Orchid               = 0xFFDA70D6,
        PaleGoldenrod        = 0xFFEEE8AA,
        PaleGreen            = 0xFF98FB98,
        PaleTurquoise        = 0xFFAFEEEE,
        PaleVioletRed        = 0xFFDB7093,
        PapayaWhip           = 0xFFFFEFD5,
        PeachPuff            = 0xFFFFDAB9,
        Peru                 = 0xFFCD853F,
        Pink                 = 0xFFFFC0CB,
        Plum                 = 0xFFDDA0DD,
        PowderBlue           = 0xFFB0E0E6,
        Purple               = 0xFF800080,
        Red                  = 0xFFFF0000,
        RosyBrown            = 0xFFBC8F8F,
        RoyalBlue            = 0xFF4169E1,
        SaddleBrown          = 0xFF8B4513,
        Salmon               = 0xFFFA8072,
        SandyBrown           = 0xFFF4A460,
        SeaGreen             = 0xFF2E8B57,
        SeaShell             = 0xFFFFF5EE,
        Sienna               = 0xFFA0522D,
        Silver               = 0xFFC0C0C0,
        SkyBlue              = 0xFF87CEEB,
        SlateBlue            = 0xFF6A5ACD,
        SlateGray            = 0xFF708090,
        Snow                 = 0xFFFFFAFA,
        SpringGreen          = 0xFF00FF7F,
        SteelBlue            = 0xFF4682B4,
        Tan                  = 0xFFD2B48C,
        Teal                 = 0xFF008080,
        Thistle              = 0xFFD8BFD8,
        Tomato               = 0xFFFF6347,
        Transparent          = 0x00FFFFFF,
        Turquoise            = 0xFF40E0D0,
        Violet               = 0xFFEE82EE,
        Wheat                = 0xFFF5DEB3,
        White                = 0xFFFFFFFF,
        WhiteSmoke           = 0xFFF5F5F5,
        Yellow               = 0xFFFFFF00,
        YellowGreen          = 0xFF9ACD32
    };

    // Shift count and bit mask for A, R, G, B components
    
    enum
    {
        AlphaShift  = 24,
        RedShift    = 16,
        GreenShift  = 8,
        BlueShift   = 0
    };

    enum
    {
        AlphaMask   = 0xff000000,
        RedMask     = 0x00ff0000,
        GreenMask   = 0x0000ff00,
        BlueMask    = 0x000000ff
    };

    // Assemble A, R, G, B values into a 32-bit integer
    
    static ARGB MakeARGB(IN BYTE a,
                         IN BYTE r,
                         IN BYTE g,
                         IN BYTE b)
    {
        return (((ARGB) (b) <<  BlueShift) |
                ((ARGB) (g) << GreenShift) |
                ((ARGB) (r) <<   RedShift) |
                ((ARGB) (a) << AlphaShift));
    }

protected:

    ARGB Argb;
};

