enum VectorFloatExpressionType_t : uint32_t
{
	VECTOR_FLOAT_EXPRESSION_UNINITIALIZED = -1,
	VECTOR_FLOAT_EXPRESSION_DOTPRODUCT = 0,
	VECTOR_FLOAT_EXPRESSION_DISTANCE = 1,
	VECTOR_FLOAT_EXPRESSION_DISTANCESQR = 2,
	VECTOR_FLOAT_EXPRESSION_INPUT1_LENGTH = 3,
	VECTOR_FLOAT_EXPRESSION_INPUT1_LENGTHSQR = 4,
	VECTOR_FLOAT_EXPRESSION_INPUT1_NOISE = 5,
};