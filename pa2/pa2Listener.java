// Generated from pa2.g4 by ANTLR 4.7.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link pa2Parser}.
 */
public interface pa2Listener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link pa2Parser#integer}.
	 * @param ctx the parse tree
	 */
	void enterInteger(pa2Parser.IntegerContext ctx);
	/**
	 * Exit a parse tree produced by {@link pa2Parser#integer}.
	 * @param ctx the parse tree
	 */
	void exitInteger(pa2Parser.IntegerContext ctx);
	/**
	 * Enter a parse tree produced by {@link pa2Parser#type}.
	 * @param ctx the parse tree
	 */
	void enterType(pa2Parser.TypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link pa2Parser#type}.
	 * @param ctx the parse tree
	 */
	void exitType(pa2Parser.TypeContext ctx);
	/**
	 * Enter a parse tree produced by {@link pa2Parser#typedAttributeList}.
	 * @param ctx the parse tree
	 */
	void enterTypedAttributeList(pa2Parser.TypedAttributeListContext ctx);
	/**
	 * Exit a parse tree produced by {@link pa2Parser#typedAttributeList}.
	 * @param ctx the parse tree
	 */
	void exitTypedAttributeList(pa2Parser.TypedAttributeListContext ctx);
	/**
	 * Enter a parse tree produced by {@link pa2Parser#operand}.
	 * @param ctx the parse tree
	 */
	void enterOperand(pa2Parser.OperandContext ctx);
	/**
	 * Exit a parse tree produced by {@link pa2Parser#operand}.
	 * @param ctx the parse tree
	 */
	void exitOperand(pa2Parser.OperandContext ctx);
	/**
	 * Enter a parse tree produced by {@link pa2Parser#attributeList}.
	 * @param ctx the parse tree
	 */
	void enterAttributeList(pa2Parser.AttributeListContext ctx);
	/**
	 * Exit a parse tree produced by {@link pa2Parser#attributeList}.
	 * @param ctx the parse tree
	 */
	void exitAttributeList(pa2Parser.AttributeListContext ctx);
	/**
	 * Enter a parse tree produced by {@link pa2Parser#openCMD}.
	 * @param ctx the parse tree
	 */
	void enterOpenCMD(pa2Parser.OpenCMDContext ctx);
	/**
	 * Exit a parse tree produced by {@link pa2Parser#openCMD}.
	 * @param ctx the parse tree
	 */
	void exitOpenCMD(pa2Parser.OpenCMDContext ctx);
	/**
	 * Enter a parse tree produced by {@link pa2Parser#closeCMD}.
	 * @param ctx the parse tree
	 */
	void enterCloseCMD(pa2Parser.CloseCMDContext ctx);
	/**
	 * Exit a parse tree produced by {@link pa2Parser#closeCMD}.
	 * @param ctx the parse tree
	 */
	void exitCloseCMD(pa2Parser.CloseCMDContext ctx);
	/**
	 * Enter a parse tree produced by {@link pa2Parser#showCMD}.
	 * @param ctx the parse tree
	 */
	void enterShowCMD(pa2Parser.ShowCMDContext ctx);
	/**
	 * Exit a parse tree produced by {@link pa2Parser#showCMD}.
	 * @param ctx the parse tree
	 */
	void exitShowCMD(pa2Parser.ShowCMDContext ctx);
	/**
	 * Enter a parse tree produced by {@link pa2Parser#writeCMD}.
	 * @param ctx the parse tree
	 */
	void enterWriteCMD(pa2Parser.WriteCMDContext ctx);
	/**
	 * Exit a parse tree produced by {@link pa2Parser#writeCMD}.
	 * @param ctx the parse tree
	 */
	void exitWriteCMD(pa2Parser.WriteCMDContext ctx);
	/**
	 * Enter a parse tree produced by {@link pa2Parser#deleteCMD}.
	 * @param ctx the parse tree
	 */
	void enterDeleteCMD(pa2Parser.DeleteCMDContext ctx);
	/**
	 * Exit a parse tree produced by {@link pa2Parser#deleteCMD}.
	 * @param ctx the parse tree
	 */
	void exitDeleteCMD(pa2Parser.DeleteCMDContext ctx);
	/**
	 * Enter a parse tree produced by {@link pa2Parser#exitCMD}.
	 * @param ctx the parse tree
	 */
	void enterExitCMD(pa2Parser.ExitCMDContext ctx);
	/**
	 * Exit a parse tree produced by {@link pa2Parser#exitCMD}.
	 * @param ctx the parse tree
	 */
	void exitExitCMD(pa2Parser.ExitCMDContext ctx);
	/**
	 * Enter a parse tree produced by {@link pa2Parser#condition}.
	 * @param ctx the parse tree
	 */
	void enterCondition(pa2Parser.ConditionContext ctx);
	/**
	 * Exit a parse tree produced by {@link pa2Parser#condition}.
	 * @param ctx the parse tree
	 */
	void exitCondition(pa2Parser.ConditionContext ctx);
	/**
	 * Enter a parse tree produced by {@link pa2Parser#conjunction}.
	 * @param ctx the parse tree
	 */
	void enterConjunction(pa2Parser.ConjunctionContext ctx);
	/**
	 * Exit a parse tree produced by {@link pa2Parser#conjunction}.
	 * @param ctx the parse tree
	 */
	void exitConjunction(pa2Parser.ConjunctionContext ctx);
	/**
	 * Enter a parse tree produced by {@link pa2Parser#comparison}.
	 * @param ctx the parse tree
	 */
	void enterComparison(pa2Parser.ComparisonContext ctx);
	/**
	 * Exit a parse tree produced by {@link pa2Parser#comparison}.
	 * @param ctx the parse tree
	 */
	void exitComparison(pa2Parser.ComparisonContext ctx);
	/**
	 * Enter a parse tree produced by {@link pa2Parser#selection}.
	 * @param ctx the parse tree
	 */
	void enterSelection(pa2Parser.SelectionContext ctx);
	/**
	 * Exit a parse tree produced by {@link pa2Parser#selection}.
	 * @param ctx the parse tree
	 */
	void exitSelection(pa2Parser.SelectionContext ctx);
	/**
	 * Enter a parse tree produced by {@link pa2Parser#projection}.
	 * @param ctx the parse tree
	 */
	void enterProjection(pa2Parser.ProjectionContext ctx);
	/**
	 * Exit a parse tree produced by {@link pa2Parser#projection}.
	 * @param ctx the parse tree
	 */
	void exitProjection(pa2Parser.ProjectionContext ctx);
	/**
	 * Enter a parse tree produced by {@link pa2Parser#atomicExpr}.
	 * @param ctx the parse tree
	 */
	void enterAtomicExpr(pa2Parser.AtomicExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link pa2Parser#atomicExpr}.
	 * @param ctx the parse tree
	 */
	void exitAtomicExpr(pa2Parser.AtomicExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link pa2Parser#renaming}.
	 * @param ctx the parse tree
	 */
	void enterRenaming(pa2Parser.RenamingContext ctx);
	/**
	 * Exit a parse tree produced by {@link pa2Parser#renaming}.
	 * @param ctx the parse tree
	 */
	void exitRenaming(pa2Parser.RenamingContext ctx);
	/**
	 * Enter a parse tree produced by {@link pa2Parser#union}.
	 * @param ctx the parse tree
	 */
	void enterUnion(pa2Parser.UnionContext ctx);
	/**
	 * Exit a parse tree produced by {@link pa2Parser#union}.
	 * @param ctx the parse tree
	 */
	void exitUnion(pa2Parser.UnionContext ctx);
	/**
	 * Enter a parse tree produced by {@link pa2Parser#difference}.
	 * @param ctx the parse tree
	 */
	void enterDifference(pa2Parser.DifferenceContext ctx);
	/**
	 * Exit a parse tree produced by {@link pa2Parser#difference}.
	 * @param ctx the parse tree
	 */
	void exitDifference(pa2Parser.DifferenceContext ctx);
	/**
	 * Enter a parse tree produced by {@link pa2Parser#product}.
	 * @param ctx the parse tree
	 */
	void enterProduct(pa2Parser.ProductContext ctx);
	/**
	 * Exit a parse tree produced by {@link pa2Parser#product}.
	 * @param ctx the parse tree
	 */
	void exitProduct(pa2Parser.ProductContext ctx);
	/**
	 * Enter a parse tree produced by {@link pa2Parser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExpr(pa2Parser.ExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link pa2Parser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExpr(pa2Parser.ExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link pa2Parser#insertCMD}.
	 * @param ctx the parse tree
	 */
	void enterInsertCMD(pa2Parser.InsertCMDContext ctx);
	/**
	 * Exit a parse tree produced by {@link pa2Parser#insertCMD}.
	 * @param ctx the parse tree
	 */
	void exitInsertCMD(pa2Parser.InsertCMDContext ctx);
	/**
	 * Enter a parse tree produced by {@link pa2Parser#query}.
	 * @param ctx the parse tree
	 */
	void enterQuery(pa2Parser.QueryContext ctx);
	/**
	 * Exit a parse tree produced by {@link pa2Parser#query}.
	 * @param ctx the parse tree
	 */
	void exitQuery(pa2Parser.QueryContext ctx);
	/**
	 * Enter a parse tree produced by {@link pa2Parser#createCMD}.
	 * @param ctx the parse tree
	 */
	void enterCreateCMD(pa2Parser.CreateCMDContext ctx);
	/**
	 * Exit a parse tree produced by {@link pa2Parser#createCMD}.
	 * @param ctx the parse tree
	 */
	void exitCreateCMD(pa2Parser.CreateCMDContext ctx);
	/**
	 * Enter a parse tree produced by {@link pa2Parser#updateCMD}.
	 * @param ctx the parse tree
	 */
	void enterUpdateCMD(pa2Parser.UpdateCMDContext ctx);
	/**
	 * Exit a parse tree produced by {@link pa2Parser#updateCMD}.
	 * @param ctx the parse tree
	 */
	void exitUpdateCMD(pa2Parser.UpdateCMDContext ctx);
	/**
	 * Enter a parse tree produced by {@link pa2Parser#command}.
	 * @param ctx the parse tree
	 */
	void enterCommand(pa2Parser.CommandContext ctx);
	/**
	 * Exit a parse tree produced by {@link pa2Parser#command}.
	 * @param ctx the parse tree
	 */
	void exitCommand(pa2Parser.CommandContext ctx);
	/**
	 * Enter a parse tree produced by {@link pa2Parser#program}.
	 * @param ctx the parse tree
	 */
	void enterProgram(pa2Parser.ProgramContext ctx);
	/**
	 * Exit a parse tree produced by {@link pa2Parser#program}.
	 * @param ctx the parse tree
	 */
	void exitProgram(pa2Parser.ProgramContext ctx);
}